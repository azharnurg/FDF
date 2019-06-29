/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 21:54:39 by anurgali          #+#    #+#             */
/*   Updated: 2019/06/07 11:09:42 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# define KEY_ESC 53

typedef struct	s_parse
{
	int			x;
	int			y;
	int			**map;
}				t_parse;

typedef struct	s_points
{
	float		x;
	float		y;
	float		z;
	int			zraw;
}				t_points;

typedef struct	s_fdfinfo
{
	t_points	**point;
	float		win_x;
	float		win_y;
	float		pix_gap;
	void		*mlx_ptr;
	void		*win_ptr;

}				t_fdfinfo;

typedef struct	s_drawvar
{
	float		delta;
	float		offset;
	float		threshold;
	float		adjust;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		distance;
	int			flat;
	float		rise;
	float		run;
	float		y;
	float		x;
	float		m;
	int			iff;
	char		*line;
	char		**split;
	char		*str;
	float		startx;
	int			zdiff;
}				t_drawvar;

typedef struct	s_count
{
	int			fd;
	int			i;
	char		*line;
	char		**split;
}				t_count;

void			setup(t_fdfinfo *info, t_parse *tp);
void			draw_right(t_fdfinfo *info, int x, int y);
void			draw_down(t_fdfinfo *info, int x, int y);
void			validation(char *av);
void			ft_error(char *str);
void			checkline(char *line);
void			draw_line(t_points point1, t_points point2, t_fdfinfo *info);
int				color1(int zdiff);
int				color2(float distance, float index);
int				color1(int zdiff);
int				color2(float distance, float index);
int				colorctrl(int flat, float distance, float index);
void			rot_z(t_points **points, int x, int y);
void			rot_y(t_points **points, int x, int y);
void			rot_x(t_points **points, int x, int y);

#endif
