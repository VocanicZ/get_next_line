/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:48:31 by marvin            #+#    #+#             */
/*   Updated: 2023/01/11 23:48:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct	s_list
{
	char			*get;
	struct s_list	*next;
}				t_list;

typedef struct	z_list 
{
	int				fd;
	struct s_list	*first;
	struct s_list	*last;
	struct z_list	*next;
}				h_list;

char	*get_next_line(int fd);
int 	ft_strlen(const char *str);
void	lst_malloc(char **line, t_list *lst);
void	lst_read(int fd, h_list **list);
int 	lst_contains(t_list *lst, char c, int mode);
void	lst_append(h_list **list, char *buf, int i);
void	lst_pop(t_list *lst, char **line);
void	lst_pop2(h_list **list);
void	lst_free(t_list *lst);
h_list *lst_get(int fd, h_list **list);
void lst_del(int fd, h_list **list);
#endif