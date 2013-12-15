/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_race.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 21:18:47 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 10:13:36 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hot_race.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

static t_elem	*init_fpush(t_elem *lst_elem)
{
	t_elem		*new_elem;

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
		return (ft_putendl(strerror(errno)));
	}
	new_elem = malloc(sizeof(t_elem));
	if (new_elem)
	{
		new_elem->keyword = NULL;
		new_elem->value = NULL;
		new_elem->next = lst_elem;
		return (new_elem);
	}
	return (ft_putendl(strerror(errno)));
}


t_elem			*get_elem(void)
{
	char		*line;
	int			i;
	t_elem		*lst_elem;
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

