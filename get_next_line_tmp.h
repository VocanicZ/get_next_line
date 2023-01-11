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

#ifndef GET_NEXT_LINE_TMP_H
# define GET_NEXT_LINE_TMP_H

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
	struct s_list	*head;
	struct s_list	*tail;
}				h_list;


char	*get_next_line(int fd);
int 	ft_strlen(const char *str);
void	ft_realloc(char **line, t_list *lst);
void	lst_read(int fd, h_list **list);//t_list **lst, t_list **last);
int 	lst_contains(t_list *lst, char c, int mode);
void	lst_append(h_list **list, char *buf, int i);//t_list **lst, char *buf, int readed, t_list **last);
void	lst_pop(t_list *lst, char **line);
void	lst_pop2(h_list **list);//t_list **lst, t_list **last);
void	lst_free(t_list *lst);
#endif