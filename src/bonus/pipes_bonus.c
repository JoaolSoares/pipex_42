/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:52:24 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/11/01 00:47:49 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	close_pipes(int **pipes, int num, int opt)
{
	int	i;

	i = 0;
	while (i < num)
	{
		close(pipes[i][1]);
		if (opt == 1)
			close(pipes[i][0]);
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

int	**open_pipes(int num)
{
	int	i;
	int	**pipefd;

	pipefd = malloc(sizeof(int *) * num);
	if (!pipefd)
		exit(60);
	i = 0;
	while (i < num)
	{
		pipefd[i] = malloc(sizeof(int) * 2);
		if (pipe(pipefd[i]) < 0)
		{
			close_pipes(pipefd, i, 1);
			exit(61);
		}
		i++;
	}
	return (pipefd);
}
