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

int color1(int zdiff){
	if(zdiff == 0)
		return (0XFF0099);
	else if(zdiff > 0)
		return(0X4B0082);
	return(0XCC9999);
}

int color2(float distance, float index)
{

	if (index <= (distance * 0.10))
		return (0xD8BFD8);
	else if (index <= (distance * 0.20))
		return (0xCC9999);
	else if (index <= (distance * 0.30))
		return (0xFF99FF);
	else if (index <= (distance * 0.40))
		return (0xCC66CC);
	else if (index <= (distance * 0.50))
		return (0xCC66FF);
	else if (index <= (distance * 0.60))
		return (0x996699);
	else if (index <= (distance * 0.70))
		return (0x9966FF);
	else if (index <= (distance * 0.80))
		return (0x9900FF);
	else if (index <= (distance * 0.90))
		return (0x660099);
	return (0x663399);

}

void draw_deci(t_drawvar *f, t_fdfinfo *info)
{
	if (f->m >= 0)
		f->adjust = 1;
	else 
		f->adjust = -1;
	f->offset = 0;
	f->threshold = 0.5;
	f->delta = fabsf(f->m);
	f->y = f->y1;
	if (f->x2 < f->x1)
	{
		ft_swap_float(&f->x1, &f->x2);
		f->y = f->y2;
	}

	float distance = f->x2 - f->x1;
	while(f->x1 <= f->x2)
	{

		mlx_pixel_put(info->mlx_ptr, info->win_ptr, f->x1, f->y, color2(distance, f->x1));
		f->offset += f->delta;
		if (f->offset >= f->threshold)
		{
			f->y += f->adjust;
			f->threshold += 1;
		}
		f->x1++;
	}
}

void draw_big_num (t_drawvar *f, t_fdfinfo *info)
{
	if (f->m >= 0)
		f->adjust = 1;
	else 
		f->adjust = -1;
	f->offset = 0;
	f->threshold = 0.5;
	f->delta = fabsf(f->run / f->rise);
	f->x = f->x1;
	if (f->y2 < f->y1)
	{
		ft_swap_float(&f->y1, &f->y2);
		f->x = f->x2;
	}
	while(f->y1 <= f->y2)
	{
		mlx_pixel_put(info->mlx_ptr, info->win_ptr, f->x, f->y1, color1(f->zdiff));
		f->offset += f->delta;
		if (f->offset >= f->threshold)
		{
			f->x += f->adjust;
			f->threshold += 1;
		}
		f->y1++;
	}
}

void draw_straight(t_drawvar *f, t_fdfinfo *info)
{
	if (f->y2 < f->y1)
		ft_swap_float(&f->y1, &f->y2);
	while (f->y1 <= f->y2)
	{
	 	mlx_pixel_put(info->mlx_ptr, info->win_ptr, f->x, f->y1, color1(f->zdiff));	
	 	f->y1++;
	}
}

void draw_line(t_points point1, t_points point2, t_fdfinfo *info)
{
	t_drawvar f;

	f.x1 = point1.x;
	f.x2 = point2.x;
	f.y1 = point1.y;
	f.y2 = point2.y;
	f.zdiff = point1.zraw - point2.zraw;

	f.rise = f.y2 - f.y1;
	f.run = f.x2 - f.x1;
	if (f.run == 0)
		draw_straight(&f, info);
	else 
	{
		f.m = (float)f.rise/f.run;
		if (f.m >= -1 && f.m <= 1)
			draw_deci(&f, info);
		else
			draw_big_num(&f, info);
	}
}
