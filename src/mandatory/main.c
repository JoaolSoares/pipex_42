/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:25:52 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/27 13:55:34 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	open_file(t_fd *fd, char *argv[])
{
	fd->fd[0] = open(argv[1], O_RDONLY);
	fd->fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd->fd[0] < 0 || fd->fd[1] < 0)
	{
		if (fd->fd[0] < 0)
			ft_printf("File Error: %s\n", argv[1]);
		if (fd->fd[1] < 0)
			ft_printf("File Error: %s\n", argv[4]);
		free(fd);
		exit(20);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_fd	*fd;
	int		status;

	if (argc != 5)
	{
		ft_printf("ERROR! Number of arguments invalid!\n");
		exit(10);
	}
	else
	{
		fd = malloc(sizeof(t_fd));
		if (!fd)
			exit(11);
		if (pipe(fd->pipefd) < 0)
			exit (12);
		open_file(fd, argv);
		first_child(fd, argv, envp);
		second_child(fd, argv, envp);
		close(fd->pipefd[0]);
		close(fd->pipefd[1]);
		waitpid(-1, &status, 0);
		waitpid(-1, &status, 0);
		free(fd);
		return (0);
	}
}
