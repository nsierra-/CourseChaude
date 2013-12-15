/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:36:11 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/15 21:03:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "gnl.h"

static int			ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		++s1;
		++s2;
	}
	if (*s1 > *s2)
		return (1);
	return (-1);
}

static void			ft_collision(t_elem *elem, char *line)
{
	t_elem			*cursor;

	cursor = elem;
	while (cursor && ft_strcmp(line, cursor->keyword) != 0)
		cursor = cursor->next;
	if (cursor != NULL && cursor->value != NULL)
		ft_putendl(cursor->value);
	else
	{
		ft_putstr(line);
		ft_putendl(": Not found.");
	}
}

void				search_keywords(t_elem **elem)
{
	char			*line;
	unsigned int	hashich;

	while (get_next_line(0, &line) > 0)
	{
		hashich = ft_hashich(line);
		if (!elem[hashich])
		{
			ft_putstr(line);
			ft_putendl(": Not found.");
		}
		else
		{
			if (ft_strcmp(line, ELEM->keyword) == 0 && ELEM->value != NULL)
				ft_putendl(elem[hashich]->value);
			else if (elem[hashich]->next != NULL)
				ft_collision(elem[hashich]->next, line);
			else
			{
				ft_putstr(line);
				ft_putendl(": Not found.");
			}
		}
		free(line);
	}
}
