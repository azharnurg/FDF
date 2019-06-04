
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

/*int deal_key(int key, void *param)
{
  if(key == 53){
    exit(0);	
  }
	return (0);
}
*/
int count(char *av, t_parse *loc)
{
	int firstline;
	int fd;
	int i;
	char *line;
	char **split;

	loc->x = 0;
	loc->y = 0;
	fd = open (av, O_RDONLY);

	//Do get next line once, y++ because thats 1 line,
	//use it to find the width/x of the line you got for your int array.
	if(ft_get_next_line(fd,&line))
	{	
		checkline(line);
		split = ft_strsplit(line, ' ');
		while(split[loc->x])
			loc->x++;
		loc->y++;
	}
	firstline = loc->x; // 19 x
	printf("First line has %d elements\n", firstline);
	//get next line returns 1 if it reads a line
	//returns 0 to break while loop when its done giving lines to you
	while (ft_get_next_line(fd, &line) > 0)
	{
		loc->y++;

		i = 0;
		checkline(line);
		split = ft_strsplit(line, ' ');
		while(split[i])
			i++;
		printf("This line has %d elements\n", i);
		if(i != firstline){
			printf("Lines didnt match, error\n");
			return (0);
		}
	}

	printf("InCount\nX = %d && Y = %d\n", loc->x, loc->y);
	close(fd);
	return (1);
}

	void storeage (char *av, t_parse *loc)
{
	int fd;
	char *line;
	char **split;
	int i = 0;
	int j = 0;


	fd = open (av, O_RDONLY);
	printf("We are in storeage\nX = %d && Y = %d\n", loc->x, loc->y);

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
	
	/*testing
	int y = 0;
	int x = 0;
	while(y < loc->y)
	{
		x = 0;
		printf("Row:%d - ", y);
		while (x < loc->x){
			printf("%d ",loc->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
	testing*/
	close(fd);

}


int main (int ac, char **av)
{
	t_parse *loc;
	t_fdfinfo *info;
	char *str;
	int fd;

	info = (t_fdfinfo *)malloc(sizeof(t_fdfinfo));
	loc = (t_parse *)malloc(sizeof(t_parse));
	if (ac == 2)
	{	
		printf("Starting FDF\n");
		if ((str = ft_strstr(av[1], ".fdf")) == 0)
			ft_error ("Error: not .fdf");
		if ((fd = open(av[1], O_RDONLY)) < 0)
			ft_error("Error: oprning");
		count(av[1], loc);
		storeage(av[1], loc);
		setup(info, loc);

	}
	else
		ft_putendl("Gimme 1 File homie\n");
	return 0;
}

