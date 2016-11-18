/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:14:19 by tdumouli          #+#    #+#             */
/*   Updated: 2016/11/18 08:14:37 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
int		verrif_piece(char *str, int y);
int		main(int ac, char **av)
{
	int		fd;
	char	buf[20];
	int		rd;

	if (ac == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (ac != 2)
	{
		write(2, "Too many arguments\n", 19);
		return (2);
	}
	if (!(fd = open(av[1], O_RDONLY)))
		return (3);
	rd = 1;
	while(rd && ((rd = read(fd, buf, 20)) != -1))
	{
		printf("%d", rd);
		if (rd != 20)
			return (1);
		if (verrif_piece(buf, 20))
			write(1, "ok\n", 3);
		else
			write(1, "ko\n", 3);
		write(1, buf, 20);
		rd = read(fd, buf, 1);
		printf(" i%di ", rd);
	}
	return (0);
}

int		verrif_piece(char *str, int size)
{
	char parcourt;
	char min;
	char max;
	
	min = -1;
	max = -1;
	parcourt = -1;
	while (++parcourt != size)
	{
		if ((((parcourt) % 5 == 4) || parcourt == 20))
		{
			if (*(str + parcourt) != '\n')
				return (0);
		}
		else
		{
			if (*(str + parcourt) != '.' && *(str + parcourt) != '#')
				return (0);
		}
		if (*(str + parcourt) == '#')
		{
			if (min = -1)
				min = parcourt;
			else if (min + 1 == parcourt)
				max = parcourt;

		}	
		write(1, parcourt + str, 1);
	}
	return (1);
}
