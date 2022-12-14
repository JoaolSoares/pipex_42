/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:03:08 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/25 23:21:51 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//	INCLUDES 
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../lib/include/libft.h"

// STRUCTS
typedef struct s_fd
{
	int	pipefd[2];
	int	fd[2];

}	t_fd;

// EXEC FUNCTIONS
void	exec_comand(char *argv, char **envp, int saved_stdout);

// FORK FUNCTIONS
void	first_child(t_fd *fd, char *argv[], char *envp[]);
void	second_child(t_fd *fd, char *argv[], char *envp[]);

#endif
