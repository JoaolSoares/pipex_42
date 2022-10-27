/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:29:23 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/27 16:54:27 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
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

static void	specific_cases(char **cmd)
{
	if (!ft_strncmp(cmd[0], "tr", ft_strlen(cmd[0])))
	{
		cmd[1] = ft_borderchar(cmd[1], 39);
		cmd[2] = ft_borderchar(cmd[2], 39);
	}
	else if (!ft_strncmp(cmd[0], "echo", ft_strlen(cmd[0])) && \
			cmd[1][0] == 39 && cmd[1][ft_strlen(cmd[1] - 1)] == 39)
		cmd[1] = ft_substr(cmd[1], 1, (ft_strlen(cmd[1]) - 2));
}

static char	**split_command(char *argv)
{
	char	*temp_cmd;
	int		i;
	char	**cmd;

	temp_cmd = ft_strdup(argv);
	i = 0;
	while (temp_cmd[i])
	{
		if (temp_cmd[i] == 39)
		{
			i++;
			while (temp_cmd[i] != 39 && temp_cmd[i])
				i++;
			i++;
		}
		if (temp_cmd[i] == ' ')
			temp_cmd[i] = -1;
		if (temp_cmd[i])
			i++;
	}
	cmd = ft_split(temp_cmd, -1);
	specific_cases(cmd);
	free(temp_cmd);
	return (cmd);
}

void	exec_comand(char *argv, char **envp, int saved_stdout)
{
	char	**cmd;
	char	**possible_paths;
	int		i;
	char	*path;

	cmd = split_command(argv);
	possible_paths = find_paths(envp);
	i = 0;
	while (possible_paths[i])
	{
		path = ft_strjoin(ft_strjoin(possible_paths[i++], "/"), cmd[0]);
		execve(path, cmd, envp);
		free(path);
	}
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	ft_printf("%s: Command Not Found\n", cmd[0]);
	free_split(cmd);
	free(possible_paths);
}
