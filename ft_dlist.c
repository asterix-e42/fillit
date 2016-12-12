/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 23:02:45 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/01 00:36:03 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_dlstadd(t_dlist **adlst, const void *conten, size_t data_siz)
{
	t_dlist	*ret;
	char	*s;

	if (!conten)
		return (2);
	if (!(ret = (t_dlist *)malloc(sizeof(t_dlist))))
		return (1);
	if (!(ret->data = malloc(data_siz)))
		return (1);
	s = (char *)ret->data;
	*(s + data_siz + 2) = 0;
	while (--data_siz)
		*(s + data_siz - 1) = *(char *)(conten + data_siz - 1);
	ret->next = NULL;
	ret->prev = (*adlst) ? *adlst : NULL;
	if (*adlst)
		(*adlst)->next = ret;
	*adlst = ret;
	return (0);
}

void	ft_dlstdelone(t_dlist **adlst)
{
	if (*adlst)
	{
		free((*adlst)->data);
		free(*adlst);
		*adlst = NULL;
	}
}

void	ft_dlstdel(t_dlist **adlst)
{
	if (*adlst)
	{
		ft_dlstdel(&((*adlst)->next));
		ft_dlstdelone(adlst);
	}
}
