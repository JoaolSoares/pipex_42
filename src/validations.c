/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:56:09 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/19 19:07:50 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	valid_arg(int argc)
{
	if (argc != 5)
	{
		ft_printf("ERROR! Number of arguments invalid!\n");
		exit(10);
	}
}
