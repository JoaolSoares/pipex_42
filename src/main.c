/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:25:52 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/19 19:27:35 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex *pipex;
	int pipefd[2];
	int fd;
	int pid1;
	int pid2;

	pipex = init_allocs();
	valid_arg(argc);
	// pipex->content = get_content(argv[1]);
	if (pipe(pipefd) == -1)
		return (20);
		
	fd = open(argv[1], O_WRONLY);
	if (fd < 0)
	{
		ft_printf("ERROR, infile doesnt exist");
		exit(21);
	}
	pid1 = fork();
	if (pid1 < 0)
		exit (22);
		//pegar o fd do infile e usar o dup pra ai ler com o comando
	
	
	free_all(pipex);
	return (0);
}
