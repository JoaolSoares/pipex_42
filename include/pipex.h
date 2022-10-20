/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:03:08 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:47:44 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//	INCLUDES 
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
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

// EXEC FUNCTIONS
void	exec_comand(char *argv, char **envp);

// fazer uma func pra dar free no split da exec

#endif