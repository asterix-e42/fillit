/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:11:58 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/05 03:06:25 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**my_little_polygone(t_dlist **mem)
{
	char	**result;
	int		nb_piece;
	int		i;

	nb_piece = 0;
	while ((*mem)->prev)
	{
		ft_resize_mem((unsigned char *)(*mem)->data);
		nb_piece += 4;
		*mem = (*mem)->prev;
	}
	ft_resize_mem((unsigned char *)(*mem)->data);
	i = 2;
	if (!(result = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	while ((i * i) < nb_piece)
	{
		++i;
	}
	if (!(result[0] = (char *)ft_memalloc(i * (i + 1))))
		return (NULL);
	if (!(result[1] = (char *)malloc(sizeof(char))))
		return (NULL);
	*result[1] = i + 1;
	return (result);
}

void	print_little_square(char **result)
{
	char i;

	i = **(result + 1) * (**(result + 1) - 1);
	while (--i != -1)
		if (i % **(result + 1) == **(result + 1) - 1)
			*(*result + i) = '\n';
		else if (!*(*result + i))
			*(*result + i) = '.';
	write(1, (*result), (**(result + 1) - 1) * **(result + 1));
}

/*
** Info
**
** Info [0] = pos;
** Info [1] = symbole;
** Info [2] = i;
*/

int		le_truc_recursif(t_dlist *mem, char **result)
{
	char	info[3];

	info[0] = 0;
	info[1] = 0;
	while ((info[2] = put_the_piece(result, mem, info[0])) != 3 || info[1] != 0)
	{
		if (info[2] == 0)
		{
			fill_square(result, mem, info[1] + 'A', info[0]);
			mem = mem->next;
			if (!mem)
				return (0);
			++info[1];
			info[0] = -1;
		}
		else if (info[2] == 3)
		{
			mem = mem->prev;
			info[0] = mem->data[2];
			--info[1];
			fill_square(result, mem, 0, info[0]);
		}
		++info[0];
	}
	return (1);
}

int		put_the_piece(char **result, t_dlist *mem, char pos)
{
	char			i;
	unsigned char	j;

	i = -1;
	j = 1;
	mem->data[2] = pos;
	while (++i != 13)
		if (mem->data[(i < 8 ? 0 : 1)] & (j = ((j == 1) ? 128 : j >> 1)))
		{
			if (*(*result + pos + i / 4 * *result[1] + i % 4) != 0)
				return (2);
			else if ((pos + i % 4) % *result[1] == *result[1] - 1)
				return (2);
			else if (pos + i % 4 + i / 4 * *result[1] >= \
					(*result[1] - 1) * (*result[1]))
				return (3);
		}
	return (0);
}

void	fill_square(char **result, t_dlist *mem, char letter, char pos)
{
	char			i;
	unsigned char	j;

	i = -1;
	j = 1;
	mem->data[2] = pos;
	while (++i != 13)
		if (mem->data[(i < 8 ? 0 : 1)] & (j = ((j == 1) ? 128 : j >> 1)))
			*(*result + pos + i / 4 * *result[1] + i % 4) = letter;
}
