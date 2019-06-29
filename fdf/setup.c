/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 00:58:05 by anurgali          #+#    #+#             */
/*   Updated: 2019/05/28 00:58:09 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			moving(t_points **points, int x, int y, t_fdfinfo *info)
{
	int			half_x_win;
	int			half_y_win;
	int			row;
	int			col;

	half_x_win = info->win_x / 2;
	half_y_win = info->win_y / 2;
	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			points[row][col].x = points[row][col].x + half_x_win;
			points[row][col].y = points[row][col].y + half_y_win;
			col++;
		}
		row++;
	}
}

t_points		**makepoints(int **map, int x, int y, int gap)
{
	t_points	**points;
	int			row;
	int			col;
	int			zmulti;

	zmulti = (-50);
	row = 0;
	points = (t_points **)malloc(sizeof(t_points *) * (y + 1));
	while (row < y)
	{
		col = 0;
		points[row] = (t_points *)malloc(sizeof(t_points) * (x + 1));
		while (col < x)
		{
			points[row][col].x = (col - (x / 2)) * gap;
			points[row][col].y = (row - (y / 2)) * gap;
			points[row][col].z = map[row][col] * zmulti;
			points[row][col].zraw = map[row][col];
			col++;
		}
		row++;
	}
	points[row] = NULL;
	return (points);
}

void			pp(t_points **points, int x, int y)
{
	int			row;
	int			col;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
			col++;
		row++;
	}
}

int				deal_key(int key, void *param)
{
	if (key == 53)
	{
		ft_putendl("IT is time to go Bye Bye");
		exit(0);
	}
	return (0);
}

void			setup(t_fdfinfo *info, t_parse *tp)
{
	info->win_x = 1600;
	info->win_y = 1200;
	info->pix_gap = tp->x > tp->y ? 600 / tp->x : 600 / tp->y;
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr,\
		info->win_x, info->win_y, "FDF");
	info->point = makepoints(tp->map, tp->x, tp->y, info->pix_gap);
	rot_x(info->point, tp->x, tp->y);
	rot_z(info->point, tp->x, tp->y);
	rot_y(info->point, tp->x, tp->y);
	moving(info->point, tp->x, tp->y, info);
	draw_right(info, tp->x, tp->y);
	draw_down(info, tp->x, tp->y);
	mlx_key_hook(info->win_ptr, deal_key, (void *)0);
	mlx_loop(info->mlx_ptr);
}
