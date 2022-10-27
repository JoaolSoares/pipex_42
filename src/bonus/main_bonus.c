/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:25:52 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/26 00:41:17 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	open_file(t_fd *fd, int argc, char *argv[])
{
	fd->fd[0] = open(argv[1], O_RDONLY);
	fd->fd[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd->fd[0] < 0 || fd->fd[1] < 0)
	{
		ft_printf("File Error!\n");
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
	if (pipe(fd->pipefd) < 0)
		exit (12);
	open_file(fd, argc, argv);
	
	first_child(fd, argv[2], envp);
	i = 3;
	while (i < argc - 2)
		middle_child(fd, argv[i++], envp);
	final_child(fd, argv[argc - 2], envp);
	
	close(fd->pipefd[0]);
	close(fd->pipefd[1]);

	waitpid(-1, &status, 0);

	free(fd);
	return (0);
}
