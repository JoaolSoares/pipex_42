/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:25:52 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/20 04:07:42 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void fork_process(t_pipex *pipex, char *argv[], char *envp[])
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		exit (22);
	if (!pipex->pid1)
	{
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		// dup2(pipex->fd2, STDOUT_FILENO);
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		exec_comand(pipex, argv, envp);
	}
	else
	{
		dup2(pipex->pipefd[0], STDIN_FILENO);
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		// dup2(pipex->fd2, STDOUT_FILENO);
		exec_comand(pipex, argv, envp);
	}
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	waitpid(pipex->pid1, NULL, 0);
}

void	open_files(t_pipex *pipex, char *argv[])
{
	pipex->fd1 = open(argv[1], O_WRONLY);
	pipex->fd2 = open("outfile", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->fd1 < 0 || pipex->fd2 < 0)
	{
		ft_printf("ERROR, infile doesnt exist"); //mudar msg
		exit(21);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex *pipex;
	int pipe_return;

	pipex = malloc(sizeof(t_pipex));
	
	valid_arg(argc);

	pipe_return = pipe(pipex->pipefd);
	if (pipe_return == -1)
		return (20);

	open_files(pipex, argv);
	fork_process(pipex, argv, envp);
	
	free(pipex);

	return (0);
}
