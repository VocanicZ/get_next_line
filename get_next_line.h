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
int 	lst_contains(t_list *list, char c);
t_list	*lst_last(t_list *list);
void	lst_read(int fd, t_list **list);
void	lst_append(t_list **list, char *buf, int readed);
void	extract_line(t_list *list, char **line);
void	generate_line(char **line, t_list *list);
void	lst_clean(t_list **list);
int 	ft_strlen(const char *str);
void	lst_free(t_list *list);
#endif