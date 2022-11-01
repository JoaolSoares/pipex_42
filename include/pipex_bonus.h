/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:03:08 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/28 14:28:41 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

//	INCLUDES 
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../lib/include/libft.h"

// STRUCTS
typedef struct s_fd
{
	int	**pipefd;
	int	filefd[2];
	int	num_pipes;
	int	index;

}	t_fd;

// EXEC FUNCTIONS
void	exec_comand(char *argv, char **envp, int saved_stdout);

// PIPE FUNCTIONS
int		**open_pipes(int num);
void	close_pipes(int **pipes, int num, int opt);

// FORK FUNCTIONS
void	call_childs(t_fd *fd, char *argv[], int argc, char *envp[]);
void	first_child(t_fd *fd, char *arg, char *envp[]);
void	middle_child(t_fd *fd, char *arg, char *envp[]);
void	final_child(t_fd *fd, char *arg, char *envp[]);

#endif
