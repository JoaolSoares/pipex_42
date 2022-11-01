/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:07:33 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/11/01 00:47:35 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	first_child(t_fd *fd, char *argv, char *envp[])
{
	pid_t	pid;
	int		saved_stdout;

	pid = fork();
	if (pid < 0)
		exit (30);
	if (pid == 0)
	{
		saved_stdout = dup(STDOUT_FILENO);
		dup2(fd->filefd[0], STDIN_FILENO);
		dup2(fd->pipefd[0][1], STDOUT_FILENO);
		close_pipes(fd->pipefd, fd->num_pipes, 1);
		exec_comand(argv, envp, saved_stdout);
		free(fd);
		exit(31);
	}
}

void	middle_child(t_fd *fd, char *argv, char *envp[])
{
	pid_t	pid;
	int		saved_stdout;

	pid = fork();
	if (pid < 0)
		exit (40);
	if (pid == 0)
	{
		saved_stdout = dup(STDOUT_FILENO);
		dup2(fd->pipefd[fd->index - 3][0], STDIN_FILENO);
		dup2(fd->pipefd[fd->index - 2][1], STDOUT_FILENO);
		close_pipes(fd->pipefd, fd->num_pipes, 0);
		exec_comand(argv, envp, saved_stdout);
		free(fd);
		exit(41);
	}
}

void	final_child(t_fd *fd, char *argv, char *envp[])
{
	pid_t	pid;
	int		saved_stdout;

	pid = fork();
	if (pid < 0)
		exit (50);
	if (pid == 0)
	{
		saved_stdout = dup(STDOUT_FILENO);
		dup2(fd->pipefd[fd->index - 3][0], STDIN_FILENO);
		dup2(fd->filefd[1], STDOUT_FILENO);
		close_pipes(fd->pipefd, fd->num_pipes, 1);
		exec_comand(argv, envp, saved_stdout);
		free(fd);
		exit(51);
	}
}

void	call_childs(t_fd *fd, char *argv[], int argc, char *envp[])
{
	fd->index = 2;
	first_child(fd, argv[fd->index], envp);
	while (++fd->index < argc - 2)
		middle_child(fd, argv[fd->index], envp);
	final_child(fd, argv[fd->index], envp);
}
