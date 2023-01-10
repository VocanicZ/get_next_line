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

typedef struct z_list
{
	struct s_list	*first;
	struct s_list	*last;
}	z_list;


char	*get_next_line(int fd);
int 	ft_strlen(const char *str);
void	ft_realloc(char **line, t_list *lst);
void	lst_read(int fd, z_list **data);
int 	lst_contains(t_list *lst, char c, int mode);
void	lst_append(char *buf, int readed, z_list **data);
void	lst_pop(z_list *data, char **line);
void	lst_pop2(z_list **data);
void	lst_free(z_list *data);
#endif