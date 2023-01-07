/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
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

int	lst_contains(t_list *list, char c)
{
	int		i;
    char    *str;

	if (!list)
		return (0);
	str = lst_last(list)->get;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* Returns a pointer to the last node in our list */

t_list	*lst_last(t_list *list)
{
	t_list	*cur;

	cur = list;
	while (cur && cur->next)
		cur = cur->next;
	return (cur);
}

/* Calculates the number of chars in the current line, including the trailing
 * \n if there is one, and allocates memory accordingly. */

void	generate_line(char **line, t_list *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->get[i])
		{
			if (list->get[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		list = list->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

/* Frees the entire list. */

void	lst_free(t_list *list)
{
	t_list	*cur;
	t_list	*next;

	current = list;
	while (cur)
	{
		free(cur->get);
		next = cur->next;
		free(cur);
		cur = next;
	}
}