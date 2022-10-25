/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:29:23 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/24 23:02:41 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{	
		free(split[i]);
		i++;
	}
	free(split);
}

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
	free_split(cmd);
	free(possible_paths);
	exit (40);
}
