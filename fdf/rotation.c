/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 01:47:33 by anurgali          #+#    #+#             */
/*   Updated: 2019/06/06 01:49:00 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rot_z(t_points **points, int x, int y)
{
	int		row;
	int		col;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			points[row][col].x = points[row][col].x * cos(0.235)\
				- points[row][col].y * sin(0.235);
			points[row][col].y = points[row][col].x * sin(0.235)\
				+ points[row][col].y * cos(0.235);
			col++;
		}
		row++;
	}
}

void		rot_y(t_points **points, int x, int y)
{
	int		row;
	int		col;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			points[row][col].x = points[row][col].x * cos(-0.74533)\
				+ points[row][col].z * sin(-0.74533);
			points[row][col].z = -(points[row][col].x * sin(-0.74533))\
				+ points[row][col].z * cos(-0.74533);
			col++;
		}
		row++;
	}
}

void		rot_x(t_points **points, int x, int y)
{
	int		row;
	int		col;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			points[row][col].y = points[row][col].y * cos(-0.2374)\
				- points[row][col].z * sin(-0.2374);
			points[row][col].z = points[row][col].y * sin(-0.2374)\
				+ points[row][col].z * cos(-0.2374);
			col++;
		}
		row++;
	}
}
