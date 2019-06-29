/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:10:37 by anurgali          #+#    #+#             */
/*   Updated: 2019/05/31 15:10:51 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_deci(t_drawvar *f, t_fdfinfo *info)
{
	f->startx = f->x1;
	f->adjust = f->m >= 0 ? 1 : -1;
	f->offset = 0;
	f->threshold = 0.5;
	f->delta = fabsf(f->m);
	f->y = f->y1;
	if (f->x2 < f->x1)
	{
		ft_swap_float(&f->x1, &f->x2);
		f->y = f->y2;
	}
	f->distance = fabsf(f->x2 - f->x1);
	while (f->x1 <= f->x2)
	{
		mlx_pixel_put(info->mlx_ptr, info->win_ptr, f->x1, f->y,\
		colorctrl(f->flat, f->distance, f->x1 - f->startx));
		f->offset += f->delta;
		if (f->offset >= f->threshold)
		{
			f->y += f->adjust;
			f->threshold += 1;
		}
		f->x1++;
	}
}

void	draw_big_num(t_drawvar *f, t_fdfinfo *info)
{
	f->adjust = f->m >= 0 ? 1 : -1;
	f->offset = 0;
	f->threshold = 0.5;
	f->delta = fabsf(f->run / f->rise);
	f->x = f->x1;
	if (f->y2 < f->y1)
	{
		ft_swap_float(&f->y1, &f->y2);
		f->x = f->x2;
	}
	while (f->y1 <= f->y2)
	{
		mlx_pixel_put(info->mlx_ptr, info->win_ptr,\
			f->x, f->y1, color1(f->zdiff));
		f->offset += f->delta;
		if (f->offset >= f->threshold)
		{
			f->x += f->adjust;
			f->threshold += 1;
		}
		f->y1++;
	}
}

void	draw_straight(t_drawvar *f, t_fdfinfo *info)
{
	if (f->y2 < f->y1)
		ft_swap_float(&f->y1, &f->y2);
	while (f->y1 <= f->y2)
	{
		mlx_pixel_put(info->mlx_ptr, info->win_ptr, f->x, f->y1,\
			color1(f->zdiff));
		f->y1++;
	}
}

int		isflat(int z1, int z2)
{
	int flat;

	flat = 0;
	if (z1 == 0 && z2 == 0)
		flat = 1;
	return (flat);
}

void	draw_line(t_points point1, t_points point2, t_fdfinfo *info)
{
	t_drawvar f;

	f.x1 = point1.x;
	f.x2 = point2.x;
	f.y1 = point1.y;
	f.y2 = point2.y;
	f.flat = isflat(point1.zraw, point2.zraw);
	f.zdiff = point1.zraw - point2.zraw;
	f.rise = f.y2 - f.y1;
	f.run = f.x2 - f.x1;
	if (f.run == 0)
		draw_straight(&f, info);
	else
	{
		f.m = (float)f.rise / f.run;
		if (f.m >= -1 && f.m <= 1)
			draw_deci(&f, info);
		else
			draw_big_num(&f, info);
	}
}
