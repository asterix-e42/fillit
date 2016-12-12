/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:14:19 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/02 02:35:54 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_dlist	*mem;
	char	**result;

	if (ac != 2)
	{
		write(1, "usage : ./fillit tetriminos_file\n", 33);
		return (1);
	}
	if (!(mem = verrif_envoie(av[1])))
	{
		write(1, "error\n", 6);
		return (2);
	}
	result = my_little_polygone(&mem);
	while (le_truc_recursif(mem, result))
		if (re_dynamique_allocation(result))
			return (2);
	print_little_square(result);
	return (0);
}

t_dlist	*verrif_envoie(char *doc)
{
	int		fd;
	char	buf[20];
	t_dlist	*mem;
	int		rd;
	char	*bite;

	mem = NULL;
	if (!(fd = open(doc, O_RDONLY)))
		return (NULL);
	rd = 1;
	bite = malloc(2);
	while (rd && ((rd = read(fd, buf, 20)) != -1))
	{
		if (rd != 20)
			return (NULL);
		*bite = 0;
		if (!verrif_piece(buf, 20, bite))
			return (NULL);
		ft_dlstadd(&mem, bite, 3);
		rd = read(fd, buf, 1);
	}
	return (mem);
}

int		verrif_piece(char *str, int size, char *bite)
{
	char parcours;
	char nb_lien;
	char nb_carre;

	nb_lien = 0;
	nb_carre = 0;
	parcours = -1;
	while (++parcours != size)
	{
		if ((parcours) % 5 == 4)
		{
			if (*(str + parcours) != '\n')
				return (0);
			if (parcours == 9)
				bite++;
		}
		else if (*(str + parcours) != '.' && *(str + parcours) != '#')
			return (0);
		else
			*bite = *bite * 2 + (*(str + parcours) == '#');
		if (*(str + parcours) == '#' && ++nb_carre)
			nb_lien += (*(str + parcours + 1) == '#') + \
						(parcours < 15 && *(str + parcours + 5) == '#');
	}
	return ((nb_carre == 4) && (nb_lien == 3 || nb_lien == 4));
}
