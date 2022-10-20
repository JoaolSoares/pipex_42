/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:25:52 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:27:02 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void child_one(t_pipex *pipex, char *argv[], char *envp[])
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		exit (22);
	if (!pipex->pid1)
	{
		close(pipex->pipefd[0]);;
		dup2(pipex->fd1, STDIN_FILENO);
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		// dup2(pipex->fd2, STDOUT_FILENO);
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		exec_comand(pipex, argv, envp);
		exit(23);
	}
	else
	{
		int status;
		
		waitpid(-1, &status, 0);
		dup2(pipex->pipefd[0], STDIN_FILENO);
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		dup2(pipex->fd2, STDOUT_FILENO);
		exec_comand(pipex, argv, envp);
		exit(24);
	}

}

// void child_two(t_pipex *pipex, char *argv[], char *envp[])
// {
// 	pipex->pid2 = fork();
// 	if (pipex->pid2 < 0)
// 		exit (22);
// 	if (!pipex->pid2)
// 	{
// 		close(pipex->pipefd[1]);
// 		dup2(pipex->fd2, STDOUT_FILENO);
// 		dup2(pipex->pipefd[0], STDIN_FILENO);
// 		// dup2(pipex->fd2, STDOUT_FILENO);
// 		// close(pipex->pipefd[0]);
// 		// close(pipex->pipefd[1]);
// 		exec_comand(pipex, argv, envp);
// 		exit(23);
// 	}
// }


void	open_files(t_pipex *pipex, char *argv[])
{
	pipex->fd1 = open(argv[1], O_RDONLY);
	pipex->fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->fd1 < 0 || pipex->fd2 < 0)
	{
		ft_printf("FILE ERROR\n");
		exit(21);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;
	// int		status;

	pipex = malloc(sizeof(t_pipex));

	valid_arg(argc);

	if (pipe(pipex->pipefd) < 0)
		return (20);

	open_files(pipex, argv);
	
	child_one(pipex, argv, envp);
	// child_one(pipex, argv, envp);
	
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	free(pipex);

	// waitpid(-1, &status, 0);
	// waitpid(-1, &status, 0);
	
	return (0);
}

	// if (!pipex->pid1)
	// {
	// 	dup2(pipex->pipefd[1], STDOUT_FILENO);
	// 	// dup2(pipex->fd2, STDOUT_FILENO);
	// 	close(pipex->pipefd[0]);
	// 	close(pipex->pipefd[1]);
	// 	exec_comand(pipex, argv, envp);
	// }
	// else
	// {
	// 	dup2(pipex->pipefd[0], STDIN_FILENO);
	// 	close(pipex->pipefd[0]);
	// 	close(pipex->pipefd[1]);
	// 	// dup2(pipex->fd2, STDOUT_FILENO);
	// 	exec_comand(pipex, argv, envp);
	// }