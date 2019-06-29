/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:10:00 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/11 19:09:26 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*str;

	str = (t_list *)malloc(sizeof(t_list));
	if (!str)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		str->content = NULL;
		str->content_size = 0;
	}
	else
	{
		str->content = malloc(sizeof(size_t) * (content_size));
		str->content = ft_memcpy(str->content, content, content_size);
		str->content_size = content_size;
	}
	return (str);
}
