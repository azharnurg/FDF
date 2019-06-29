/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:50:14 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/11 18:58:14 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *l;
	t_list *nextl;

	l = *alst;
	while (l)
	{
		nextl = l->next;
		del(l->content, l->content_size);
		free(l);
		l = nextl;
	}
	*alst = NULL;
}
