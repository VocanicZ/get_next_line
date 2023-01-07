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
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
int 	ft_contains(t_list *list);
t_list	*ft_get_last(t_list *list);
void	read_and_list(int fd, t_list **list);
void	add_to_list(t_list **list, char *buf, int readed);
void	extract_line(t_list *list, char **line);
void	generate_line(char **line, t_list *list);
void	clean_list(t_list **list);
int 	ft_strlen(const char *str);
void	free_list(t_list *list);
#endif