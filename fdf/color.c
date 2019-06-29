/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:44:26 by anurgali          #+#    #+#             */
/*   Updated: 2019/06/05 23:45:04 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color1(int zdiff)
{
	if (zdiff == 0)
		return (0x6A359C);
	else if (zdiff > 0)
		return (0x552586);
	return (0XCC9999);
}

int	color2(float distance, float index)
{
	if (index <= (distance * 0.10))
		return (0x552586);
	else if (index <= (distance * 0.20))
		return (0x6A359C);
	else if (index <= (distance * 0.30))
		return (0x804FB3);
	else if (index <= (distance * 0.40))
		return (0x9969C7);
	else if (index <= (distance * 0.50))
		return (0xB589D6);
	else if (index <= (distance * 0.60))
		return (0xD780DE);
	else if (index <= (distance * 0.70))
		return (0xD993E9);
	else if (index <= (distance * 0.80))
		return (0xDDA5F7);
	else if (index <= (distance * 0.90))
		return (0xE0B0FE);
	return (0xE0B0FE);
}

int	colorctrl(int flat, float distance, float index)
{
	if (flat == 1)
		return (0x552586);
	return (color2(distance, index));
}
