/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 21:26:39 by anurgali          #+#    #+#             */
/*   Updated: 2019/05/17 21:29:42 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				count(char *av, t_parse *loc)
{
	t_count		cnt;

	loc->x = 0;
	loc->y = 0;
	cnt.fd = open(av, O_RDONLY);
	while (ft_get_next_line(cnt.fd, &cnt.line) > 0)
	{
		loc->y++;
		cnt.i = 0;
		checkline(cnt.line);
		cnt.split = ft_strsplit(cnt.line, ' ');
		while (cnt.split[cnt.i])
			cnt.i++;
		if (loc->x == 0)
			loc->x = cnt.i;
		else if (cnt.i != loc->x)
			ft_error("Error: width didn't match");
	}
	close(cnt.fd);
	return (1);
}

void			storeage(char *av, t_parse *loc)
{
	int			fd;
	char		*line;
	char		**split;
	int			i;
	int			j;

	i = 0;
	j = 0;
	fd = open(av, O_RDONLY);
	loc->map = (int **)malloc(sizeof(int *) * (loc->y));
	i = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		loc->map[i] = (int *)malloc(sizeof(int) * loc->x);
		split = ft_strsplit(line, ' ');
		j = 0;
		while (split[j])
		{
			loc->map[i][j] = ft_atoi(split[j]);
			j++;
		}
		i++;
	}
	close(fd);
}

int				main(int ac, char **av)
{
	t_parse		*loc;
	t_fdfinfo	*info;
	char		*str;
	int			fd;

	info = (t_fdfinfo *)malloc(sizeof(t_fdfinfo));
	loc = (t_parse *)malloc(sizeof(t_parse));
	if (ac == 2)
	{
		if ((str = ft_strstr(av[1], ".fdf")) == 0)
			ft_error("Error: not .fdf");
		if ((fd = open(av[1], O_RDONLY)) < 0)
			ft_error("Error: oprning");
		count(av[1], loc);
		storeage(av[1], loc);
		setup(info, loc);
	}
	else
		ft_putendl("Gimme 1 File homie\n");
	return (0);
}
