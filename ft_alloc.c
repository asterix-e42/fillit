/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 07:49:32 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/05 02:33:44 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_resize_mem(unsigned char bite[2])
{
	if (!bite[0])
	{
		bite[0] = bite[1];
		bite[1] = 0;
	}
	if (bite[0] < 16)
		bite[0] = ((bite[0] << 4) + (bite[1] >> 4)) + ((bite[1] <<= 4) & 0);
	while (!(*bite & 128) & !(*bite & 8) & !(bite[1] & 128) & !(bite[1] & 8))
	{
		bite[0] <<= 1;
		bite[1] <<= 1;
	}
}

char	re_dynamique_allocation(char **result)
{
	free(result[0]);
	if (!(*result = ft_memalloc(sizeof(char) * (++**(result + 1)) * \
					(**(result + 1) + 1) + 1)))
		return (1);
	return (0);
}

void	*ft_memalloc(int i)
{
	char	*str;

	if (!(str = malloc(i)))
		return (NULL);
	while (i--)
		str[i] = '\0';
	return (str);
}
