/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:25:52 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/24 23:01:44 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	open_file(int *fd, char *argv[])
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
	int		pipefd[2];
	int		fd[2];
	int		status;

	if (argc != 5)
	{
		ft_printf("ERROR! Number of arguments invalid!\n");
		exit(10);
	}
	if (pipe(pipefd) < 0)
		exit (11);
	open_file(fd, argv);
	fork_process(pipefd, fd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (0);
}
