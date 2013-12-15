/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:17:38 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/15 22:37:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "gnl.h"
#include <string.h>
#include <errno.h>

static t_elem		*ft_build_keyword(t_elem **elem, char *line,
										t_cui hashich, t_to_free *to_free)
{
	if (!elem[hashich])
	{
		elem[hashich] = malloc(sizeof(t_elem));
		if (!elem[hashich])
			return (ft_putendl(strerror(errno)));
		to_free->elem = elem[hashich];
		elem[hashich]->keyword = line;
		to_free->keyword = line;
		elem[hashich]->value = NULL;
		elem[hashich]->next = NULL;
		return (elem[hashich]);
	}
	else
	{
		if (ft_strcmp_ns(elem[hashich]->keyword, line) != 0)
			return (ft_pop_elem(elem[hashich], line));
		else
			return (elem[hashich]);
	}
}

static t_to_free	*lst_init(void)
{
	t_to_free		*new_lst;

	new_lst = malloc(sizeof(t_to_free));
	if (new_lst)
	{
		new_lst->keyword = NULL;
		new_lst->value = NULL;
		new_lst->elem = NULL;
		new_lst->next = NULL;
		return (new_lst);
	}
	return (ft_putendl(strerror(errno)));
}

static t_to_free	*lst_fpush(t_to_free *to_free)
{
	t_to_free		*new_elem;

	new_elem = malloc(sizeof(t_to_free));
	if (new_elem)
	{
		new_elem->keyword = NULL;
		new_elem->value = NULL;
		new_elem->elem = NULL;
		new_elem->next = to_free;
		return (new_elem);
	}
	return (ft_putendl(strerror(errno)));
}

static t_to_free	*init_push(t_to_free *to_free)
{
	if (to_free == NULL)
		return(lst_init());
	else
		return(lst_fpush(to_free));
}

int					main(void)
{
	static t_elem	*elem[HASH_TABLE_SIZE];
	t_elem			*tmp;
	t_to_free		*to_free;
	char			*line;
	int				i;

	i = 0;
	to_free = NULL;
	while (get_next_line(0, &line) > 0 && ft_strcmp_ns("", line) != 0)
	{
		if (i % 2 == 0)
		{
			to_free = init_push(to_free);
			tmp = ft_build_keyword(elem, line, ft_hashich(line), to_free);
		}
		else
		{
			tmp->value = line;
			to_free->value = tmp->value;
		}
		++i;
	}
	search_keywords(elem);
	free_the_slaves(to_free);
	return (0);
}
