/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasuphar <nasuphar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:17:35 by nasuphar          #+#    #+#             */
/*   Updated: 2023/01/27 00:08:43 by nasuphar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_GET_NEXT_LINE_H
# define NEW_GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct c_list
{
	int					fd;
	char				*first;
	char				*last;
	struct c_list		*next;
}	t_circular;

t_circular	*lst_get(int fd, t_circular **list);
void		lst_del(int fd, t_circular **list);
void		lst_print(t_circular *list);
char		*get_next_line(int fd);
int     is_contain(char *str, char c, int returnIndex);
void    lst_read(t_circular *list);
char    *fd_pcat(char **dest, char *s1, char *s2);
void    lst_append(t_circular *list, char *buf, int i);
#endif