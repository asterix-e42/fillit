/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 21:39:45 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/05 03:06:46 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_dlist
{

	struct s_dlist	*next;
	struct s_dlist	*prev;
	char			*data;
}				t_dlist;

int				le_truc_recursif(t_dlist *mem, char **result);
int				put_the_piece(char **result, t_dlist *mem, char pos);
char			**my_little_polygone(t_dlist **r);
void			print_little_square(char **result);
int				verrif_piece(char *str, int y, char *bite);
t_dlist			*verrif_envoie(char *doc);
int				ft_dlstadd(t_dlist **adlst, const void *conten, size_t siz);
void			ft_dlstdelone(t_dlist **adlst);
void			ft_dlstdel(t_dlist **adlst);
void			ft_resize_mem(unsigned char bite[2]);
void			fill_square(char **result, t_dlist *mem, char letter, char pos);
char			re_dynamique_allocation(char **result);
void			*ft_memalloc(int	i);

#endif
