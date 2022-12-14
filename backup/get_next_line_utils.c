/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:40:00 by marvin            #+#    #+#             */
/*   Updated: 2022/11/05 20:40:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	lst_contains(t_list *lst, char c, int mode)
{
	int		i;
    char    *str;

	if (!lst)
		return (0);
	str = lst->get;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (mode)
				return (i);
			return (1);
		}
		i++;
	}
	if (mode)
		return (i);
	return (0);
}

void	lst_malloc(char **line, t_list *lst)
{
	int	i;
	int	len;
    char    *str;

	len = 0;
	while (lst)
	{
		i = 0;
        str = lst->get;
		while (str[i])
		{
			if (str[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		lst = lst->next;
	}
	*line = (char *) malloc(sizeof(char) * (len + 1));
}

void	lst_free(t_list *lst)
{
	t_list	*cur;
	t_list	*next;

	cur = lst;
	while (cur)
	{
		free(cur->get);
		next = cur->next;
		free(cur);
		cur = next;
	}
}