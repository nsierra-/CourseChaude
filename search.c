/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 09:44:01 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 10:56:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hot_race.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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
		new_output->next = out;
		return (new_output);
	}
	return (ft_putendl(strerror(errno)));
}

#include <stdio.h>
static void		print_list(t_output *out)
{
	t_output	*cursor;

	cursor = out;
	while (cursor != NULL)
	{
		if (cursor->found == TRUE)
		{
			ft_putendl(cursor->value);
		}
		else
		{
			ft_putstr(cursor->keyword_to_find);
			ft_putendl(": Not found.");
		}
		cursor = cursor->next;
	}
}

/* static void		ft_puterror(char *line) */
/* { */
/* 	ft_putstr(line); */
/* 	ft_putchar(':'); */
/* 	ft_putendl(" Not found."); */
/* } */

static void		compare_line(const t_elem *current_elem, t_output *out)
{
	t_output	*cursor;

	cursor = out;
	while (cursor != NULL)
	{
		if (cursor->found == TRUE)
			cursor = cursor->next;
		else if (ft_strcmp(cursor->keyword_to_find, current_elem->keyword) == 0)
		{
			cursor->value = current_elem->value;
			cursor->found = TRUE;
			break ;
		}
		else
			cursor = cursor->next;
	}
}

t_elem			*search_keyword(t_elem *lst_elem)
{
	char		*line;
	t_output	*out;
	t_elem		*cursor;

	out = NULL;
	cursor = lst_elem;
	while (get_next_line(0, &line) > 0)
		out = fpush_output(out, line);
	while (cursor != NULL)
	{
		compare_line(cursor, out);
		cursor = cursor->next;
	}
	print_list(out);
	/* print_list(out); */
	/* while (get_next_line(0, &line) > 0) */
	/* { */
	/* 	check = 1; */
	/* 	cursor = lst_elem; */
	/* 	while (cursor != NULL && check) */
	/* 	{ */
	/* 		if (ft_strcmp(cursor->keyword, line) == 0) */
	/* 		{ */
	/* 			ft_putendl(cursor->value); */
	/* 			check = 0; */
	/* 		} */
	/* 		else if (cursor->next == NULL) */
	/* 		{ */
	/* 			ft_puterror(line); */
	/* 			check = 0; */
	/* 		} */
	/* 		else */
	/* 			cursor = cursor->next; */
	/* 	} */
	/* } */
	return (lst_elem);
}
