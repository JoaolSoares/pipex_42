/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:03:08 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/24 22:52:58 by jlucas-s         ###   ########.fr       */
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

// EXEC FUNCTIONS
void	exec_comand(char *argv, char **envp);

// FORK FUNCTIONS
void	fork_process(int *pipefd, int *fd, char *argv[], char *envp[]);

// QUANDO TEM UM COMANDO ERRADO ELE DA LEAK

#endif