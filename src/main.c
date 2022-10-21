/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:25:52 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/21 23:33:57 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	open_files(int *fd, char *argv[])
{
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd[0] < 0 || fd[1] < 0)
	{
		ft_printf("FILE ERROR\n");
		exit(20);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		pipefd[2];
	int		status;

	if (argc != 5)
	{
		ft_printf("ERROR! Number of arguments invalid!\n");
		exit(10);
	}
	else
	{
		if (pipe(pipefd) < 0)
			return (11);
		open_files(fd, argv);
		fork_process(pipefd, fd, argv, envp);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(-1, &status, 0);
		waitpid(-1, &status, 0);
	}
	return (0);
}
