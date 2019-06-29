/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:30:56 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/11 19:33:36 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *fresh;

	fresh = f(lst);
	new = fresh;
	while (lst->next)
	{
		lst = lst->next;
		if (!(fresh->next = f(lst)))
		{
			free(fresh->next);
			return (NULL);
		}
		fresh = fresh->next;
	}
	return (new);
}
