/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:03:08 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/20 03:48:25 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//	INCLUDES 
# include <sys/types.h>
# include <sys/stat.h>
 #include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../lib/include/libft.h"

typedef struct s_pipex
{
	int		pipefd[2];
	int		fd1;
	int		fd2;
	pid_t	pid1;
	pid_t	pid2;
	
}	t_pipex;

// READ FUNCTIONS
char	*get_content(char *infile);

// VALIDATION FUNCTIONS
void	valid_arg(int argc);

void	exec_comand(t_pipex *pipex, char **argv, char **envp);

// ALLOC FUNCTIONS
// t_pipex	*init_allocs(void);
// void	free_all(t_pipex *pipex);

#endif