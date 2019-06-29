/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 23:50:27 by anurgali          #+#    #+#             */
/*   Updated: 2019/06/01 23:55:17 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		ft_findw(char **coord)
{
	int		x;

	x = 0;
	while (coord[x])
		x++;
	return (x);
}

void	checkline(char *line)
{
	int i;

	i = 0;
	if (!line[i])
		ft_error("Error: line read");
	if (ft_strlen(&line[i]) <= 2)
		ft_error("Error: too little line");
	while (line[i] != '\0')
	{
		if (ft_isalpha(line[i]))
			ft_error("Error: alphabet chars found");
		if ((line[i] == '-' && !(ft_isdigit(line[i + 1]))) || line[i] == '\t')
			ft_error("Error: forbidden chars");
		i++;
	}
}
