/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:07:33 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/26 13:12:14 by jlucas-s         ###   ########.fr       */
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
		dup2(fd->fd[0], STDIN_FILENO);
		dup2(fd->pipefd[1], STDOUT_FILENO);
		close(fd->pipefd[0]);
		close(fd->pipefd[1]);
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
		dup2(fd->pipefd[0], STDIN_FILENO);
		dup2(fd->pipefd[1], STDOUT_FILENO);
		close(fd->pipefd[0]);
		close(fd->pipefd[1]);
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
		dup2(fd->fd[1], STDOUT_FILENO);
		dup2(fd->pipefd[0], STDIN_FILENO);
		close(fd->pipefd[0]);
		close(fd->pipefd[1]);
		exec_comand(argv, envp, saved_stdout);
		free(fd);
		exit(51);
	}
}
