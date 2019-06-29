/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:21:11 by anurgali          #+#    #+#             */
/*   Updated: 2019/04/03 20:34:05 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int			readfile(const int fd, char **buf)
{
	char	temp[BUFF_SIZE + 1];
	int		read_amount;
	char	*leak_checker;

	read_amount = 0;
	while ((read_amount = read(fd, temp, BUFF_SIZE)) > 0)
	{
		temp[read_amount] = '\0';
		leak_checker = buf[fd];
		buf[fd] = ft_strjoin(buf[fd], temp);
		if (!buf[fd])
			buf[fd] = ft_strdup(temp);
		//free(leak_checker);
		ft_bzero(temp, BUFF_SIZE);
	}
	if (read_amount < 0)
		return (0);
	return (1);
}

int			findline(int fd, char **buf, char **line)
{
	char	*loc;

	if ((loc = ft_strchr(buf[fd], '\n')))
	{
		*loc = '\0';
		*line = ft_strdup(buf[fd]);
		buf[fd] = loc + 1;
		return (1);
	}
	else if (ft_strlen(buf[fd]) > 0)
	{
		*line = ft_strdup(buf[fd]);
		buf[fd] = buf[fd] + ft_strlen(buf[fd]);
		return (1);
	}
	return (0);
}

int			ft_get_next_line(const int fd, char **line)
{
	static	char *buf[256];

	if (!line || BUFF_SIZE < 1 || fd < 0 || !readfile(fd, buf))
		return (-1);
	if (findline(fd, buf, line))
		return (1);
	return (0);
}
