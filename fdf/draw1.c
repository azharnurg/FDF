/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 04:34:44 by anurgali          #+#    #+#             */
/*   Updated: 2019/06/01 04:34:49 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_right(t_fdfinfo *info, int x, int y)
{
	int row;
	int col;

	row = 0;
	while (row < y)
	{
		col = 0;
		while ((col + 1) < x)
		{
			draw_line(info->point[row][col], info->point[row][col + 1], info);
			col++;
		}
		row++;
	}
}

void	draw_down(t_fdfinfo *info, int x, int y)
{
	int row;
	int col;

	row = 0;
	while ((row + 1) < y)
	{
		col = 0;
		while (col < x)
		{
			draw_line(info->point[row][col], info->point[row + 1][col], info);
			col++;
		}
		row++;
	}
}
