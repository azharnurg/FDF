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

void moving(t_points **points, int x, int y, t_fdfinfo *info)
{
	int half_x_win;
	int half_y_win;
	int row;
	int col;

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

void rot_z(t_points **points, int x, int y)
{
	int row;
	int col;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
	
			points[row][col].x = points[row][col].x * cos(0.7854) - points[row][col].y * sin(0.7854); 
			points[row][col].y = points[row][col].x * sin(0.7854) + points[row][col].y * cos(0.7854);
			col++;
		}		
		row++;
	}
}

void rot_y(t_points **points, int x, int y)
{
	int row;
	int col;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			points[row][col].x = points[row][col].x * cos(0.0524) + points[row][col].z * sin(0.0524); //45 degrees in radians
			points[row][col].z = -(points[row][col].x * sin(0.0524)) + points[row][col].z * cos(0.0524);
			col++;
		}		
		row++;
	}
}

void rot_x(t_points **points, int x, int y)
{
	int row;
	int col;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			points[row][col].x = points[row][col].y * cos(0.6982) - points[row][col].z * sin(0.6982); //45 degrees in radians
			points[row][col].z = points[row][col].y * sin(0.6982) + points[row][col].z * cos(0.6982);
			col++;
		}		
		row++;
	}
}

t_points **makepoints(int **map, int x, int y, int gap)
{
	t_points **points;
	int row;
	int col;
	int mid_x;
	int mid_y;

	mid_x = x/2;
	mid_y = y/2;
	row = 0;
	points = (t_points **)malloc(sizeof(t_points *) * (y + 1));
	while (row < y)
	{
		col = 0;
		points[row] = (t_points *)malloc(sizeof(t_points) * (x + 1));
		while (col < x)//create an array that stores your pixel coordinates
		{//the middle of that pixel array is 0,0
			//(10-10) * 35 = 0 
			points[row][col].x = (col - mid_x) * gap;
			points[row][col].y = (row - mid_y) * gap;
			points[row][col].z = map[row][col] * 5; //multiply by 5 cause z is too small
			points[row][col].zraw = map[row][col];

			col++;
		}
		row++;
	}
	points[row] = NULL;
	return (points);
}

void PP(t_points **points, int x, int y){
//delete later, testing only;
	int row = 0;
	int col;

	while(row < y){

		col = 0;
		while(col < x){
			printf("[X:%f,Y:%f] ", points[row][col].x, points[row][col].y);
			col++;
		}
		printf("\n");
		row++;
	}
}

int deal_key(int key, void *param)
{

	printf("Keycode: %d\n", key);

  if(key == 53){
    printf("IT is time to go Bye Bye\n");
    printf("Love you\n");
    exit(0);	
  }
	return (0);

}

void setup(t_fdfinfo *info, t_parse *tp)
{
	info->win_x = 1200;
	info->win_y = 1000;
	info->pix_gap = tp->x > tp->y ? 700 /tp->x : 700/tp->y;
	info->mlx_ptr = mlx_init();
  	info->win_ptr = mlx_new_window(info->mlx_ptr, info->win_x, info->win_y, "FDF");
	printf("Win X %f - Win Y %f\nGap: %f\n", info->win_x, info->win_y, info->pix_gap);
	info->x_lim = tp->x;
	info->y_lim = tp->y;
	info->point = makepoints(tp->map, tp->x, tp->y, info->pix_gap);
	rot_z(info->point, tp->x, tp->y);
	rot_x(info->point, tp->x, tp->y);
	rot_y(info->point, tp->x, tp->y);
	moving(info->point, tp->x, tp->y, info);
	draw_right(info, tp->x, tp->y, 0XD8BFD8);
	draw_down(info, tp->x, tp->y, 0XD8BFD8);
	mlx_key_hook(info->win_ptr, deal_key, (void *)0);
 	 mlx_loop(info->mlx_ptr);
}

