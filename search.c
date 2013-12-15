/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 09:44:01 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/15 03:39:38 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hot_race.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

static t_output	*fpush_output(t_output *out, char *line)
{
	t_output	*new_output;
	static int	index = 1;

	new_output = malloc(sizeof(t_output));
	if (new_output)
	{
		new_output->keyword_to_find = line;
		new_output->value = NULL;
		new_output->found = FALSE;
		new_output->index = index++;
		new_output->next = NULL;
		new_output->prev = out->tail;
		new_output->tail = new_output;
		out->tail->next = new_output;
		out->tail = new_output;
		return (out);
	}
	return (ft_putendl(strerror(errno)));
}

static void		print_list(t_output *out)
{
	t_output	*cursor;

	cursor = out;
	while (cursor != NULL)
	{
		if (cursor->found == TRUE)
			ft_putendl(cursor->value);
		else
		{
			ft_putstr(cursor->keyword_to_find);
			ft_putendl(": Not found.");
		}
		cursor = cursor->next;
	}
}

static void		compare_line(const t_elem *current_elem, t_output *out)
{
	t_output	*cursor;

	cursor = out;
	while (cursor != NULL)
	{
		if (ft_strcmp(cursor->keyword_to_find, current_elem->keyword) == 0
				&& cursor->found == FALSE)
		{
			cursor->value = current_elem->value;
			cursor->found = TRUE;
		}
		cursor = cursor->next;
	}
}

static t_output	*init_out(t_output *out, char *line)
{
	out = malloc(sizeof(t_output));
	if (out)
	{
	out->keyword_to_find = line;
	out->value = NULL;
	out->found = FALSE;
	out->index = 1;
	out->next = NULL;
	out->prev = NULL;
	out->tail = out;
	return (out);
	}
	return (ft_putendl(strerror(errno)));
}

t_elem			*search_keyword(t_elem *lst_elem)
{
	char		*line;
	t_output	*out;
	t_elem		*cursor;

	out = NULL;
	if (get_next_line(0, &line) > 0)
		out = init_out(out, line);
	cursor = lst_elem;
	while (get_next_line(0, &line) > 0)
		out = fpush_output(out, line);
	while (cursor != NULL)
	{
		compare_line(cursor, out);
		cursor = cursor->next;
	}
	print_list(out);
	while (out->next != NULL)
	{
		free(out->keyword_to_find);
		out = out->next;
		free(out->prev);
	}
	free(out->keyword_to_find);
	free(out);
	return (lst_elem);
}
