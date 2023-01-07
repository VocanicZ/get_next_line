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

/*# include <sys/types.h>
# include <sys/uio.h>*/
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct	s_list
{
	char			*get;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
int 	lst_contains(t_list *lst, char c);
t_list	*lst_last(t_list *lst);
void	lst_read(int fd, t_list **lst);
void	lst_append(t_list **lst, char *buf, int readed);
void	lst_get(t_list *lst, char **line);
void	ft_realloc(char **line, t_list *lst);
void	lst_clean(t_list **lst);
int 	ft_strlen(const char *str);
void	lst_free(t_list *lst);
#endif