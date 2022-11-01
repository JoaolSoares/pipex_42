/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:25:52 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/31 21:32:13 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	open_file(t_fd *fd, int argc, char *argv[])
{
	fd->filefd[0] = open(argv[1], O_RDONLY);
	fd->filefd[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd->filefd[0] < 0 || fd->filefd[1] < 0)
	{
		if (fd->filefd[0] < 0)
			ft_printf("File Error: %s\n", argv[1]);
		if (fd->filefd[1] < 0)
			ft_printf("File Error: %s\n", argv[argc - 1]);
		free(fd);
		exit(20);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_fd	*fd;
	int		status;
	int		i;

	if (argc < 3)
	{
		ft_printf("Error! Number of Arguments Incorret.\n");
		exit (1);
	}
	fd = malloc(sizeof(t_fd));
	if (!fd)
		exit(11);
	open_file(fd, argc, argv);
	fd->num_pipes = argc - 4;
	fd->pipefd = open_pipes(fd->num_pipes);
	call_childs(fd, argv, argc, envp);
	close_pipes(fd->pipefd, fd->num_pipes, 1);
	waitpid(-1, &status, 0);
	free(fd);
	return (0);
}
