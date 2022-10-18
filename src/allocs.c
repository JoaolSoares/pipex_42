/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:56:56 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/18 01:58:50 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipex	*init_allocs(void)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	return (pipex);
}

void	free_all(t_pipex *pipex)
{
	free(pipex->content);
	free(pipex);
}