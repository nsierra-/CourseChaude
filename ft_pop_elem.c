/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:34:37 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/15 20:35:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

t_elem		*ft_pop_elem(t_elem *elem, char *line)
{
	t_elem	*new_elem;
	t_elem	*cursor;

	cursor = elem;
	new_elem = malloc(sizeof(t_elem));
	if (new_elem)
	{
		new_elem->keyword = line;
		new_elem->value = NULL;
		new_elem->next = NULL;
		while (ft_strcmp(cursor->keyword, line) != 0 && cursor->next != NULL)
			cursor = cursor->next;
		if (cursor->next == NULL && ft_strcmp(cursor->keyword, line) != 0)
		{
			cursor->next = new_elem;
			return (new_elem);
		}
		else
		{
			free(new_elem);
			return (cursor);
		}
	}
	else
		return (ft_putendl(strerror(errno)));
}
