/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:29:23 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:54:35 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**find_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

void	exec_comand(char *argv, char **envp)
{
	char	**cmd;
	char	**possible_paths;
	int		i;
	char	*path;

	cmd = ft_split(argv, ' ');
	possible_paths = find_paths(envp);
	i = 0;
	while (possible_paths[i])
	{
		path = ft_strjoin(ft_strjoin(possible_paths[i], "/"), cmd[0]);
		execve(path, cmd, envp);
		free(path);
		i++;
	}
	exit (40);
}
