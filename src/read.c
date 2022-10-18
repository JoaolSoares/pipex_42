/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:46:17 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/18 02:01:31 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_content(char	*infile)
{
	int		fd;
	char	*buffer;
	char	*content;
	
	fd = open(infile, O_RDONLY);
	if (fd < 0)
		exit(20);
	buffer = get_next_line(fd);
	content = NULL;
	while (buffer)
	{
		content = ft_strjoin(content, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (content);
}