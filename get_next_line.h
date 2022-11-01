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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);
size_t  ft_strchr(const char *s, int c);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strtrim(const char *s, size_t start, size_t stop);
#endif