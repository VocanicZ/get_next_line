/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:14:38 by marvin            #+#    #+#             */
/*   Updated: 2022/10/31 23:14:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct	s_list
{
	char			*get;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
int 	ft_strlen(const char *str);
void	ft_realloc(char **line, t_list *lst);
void	lst_read(int fd, t_list **lst);
int 	lst_contains(t_list *lst, char c);
void	lst_append(t_list **lst, char *buf, int readed);
t_list	*lst_last(t_list *lst);
void	lst_pop(t_list *lst, char **line);
void	lst_pop2(t_list **lst);
void	lst_free(t_list *lst);
#endif