/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:07:33 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/24 23:00:10 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	fork_process(int *pipefd, int *fd, char *argv[], char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit (30);
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		exec_comand(argv[2], envp);
	}
	pid = fork();
	if (pid < 0)
		exit (32);
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		exec_comand(argv[3], envp);
	}
}
