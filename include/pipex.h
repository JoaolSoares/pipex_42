/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:03:08 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/19 18:55:52 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//	INCLUDES 
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../lib/include/libft.h"

typedef struct s_pipex
{
	char *content;
	
}	t_pipex;

// READ FUNCTIONS
char	*get_content(char *infile);

// VALIDATION FUNCTIONS
void	valid_arg(int argc);

// ALLOC FUNCTIONS
t_pipex	*init_allocs(void);
void	free_all(t_pipex *pipex);

#endif