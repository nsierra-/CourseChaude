/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_race.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 21:18:47 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 09:02:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hot_race.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

static t_elem   *init_fpush(t_elem *lst_elem)
{
	t_elem      *new_elem;
	if (lst_elem == NULL)
	{
		lst_elem = malloc(sizeof(t_elem));
		if (lst_elem)
		{
			lst_elem->keyword = NULL;
			lst_elem->value = NULL;
			lst_elem->next = NULL;
			return (lst_elem);
		}
		ft_putendl(strerror(errno));
		return (NULL);
	}
	new_elem = malloc(sizeof(t_elem));
	if (new_elem)
	{
		new_elem->keyword = NULL;
		new_elem->value = NULL;
		new_elem->next = lst_elem;
		return (new_elem);
	}
	ft_putendl(strerror(errno));
	return (NULL);
}

static void		ft_puterror(char *line)
{
	ft_putstr(line);
	ft_putchar(':');
	ft_putendl(" Not found.");
}

t_elem     *get_elem(void)
{
	char        *line;
	int         i;
	t_elem      *lst_elem;
	t_elem		*tmp;

	lst_elem = NULL;
	lst_elem = init_fpush(lst_elem);
	i = 0;
	while (get_next_line(0, &line) > 0 && ft_strcmp(line, "") != 0)
	{
		if (i % 2 == 0)
			lst_elem->keyword = line;
		else if (i % 2 == 1)
		{
			lst_elem->value = line;
			lst_elem = init_fpush(lst_elem);
		}
		i++;
	}
	tmp = lst_elem->next;
	free(lst_elem);
	return (tmp);
}

t_elem			*search_keyword(t_elem *lst_elem)
{
	char		*line;
	int			check;
	t_elem		*cursor;

	while (get_next_line(0, &line) > 0)
	{
		check = 1;
		cursor = lst_elem;
		while (cursor != NULL && check)
		{
			if (ft_strcmp(cursor->keyword, line) == 0)
			{
				ft_putendl(cursor->value);
				check = 0;
			}
			else if (cursor->next == NULL)
			{
				ft_puterror(line);
				check = 0;
			}
			else
				cursor = cursor->next;
		}
	}
	return (lst_elem);
}

int				free_the_slaves(t_elem *lst_elem)
{
	t_elem		*tmp;
	t_elem		*cursor;

	cursor = lst_elem;
	while (cursor != NULL)
	{
		tmp = cursor;
		cursor = cursor->next;
		free(tmp->keyword);
		free(tmp->value);
		free(tmp);
	}
	return (0);
}

