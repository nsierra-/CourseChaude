/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:48:40 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/15 20:49:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

void				free_the_slaves(t_to_free *to_free)
{
	t_to_free		*cursor;
	t_to_free		*tmp;

	cursor = to_free;
	while (cursor != NULL)
	{
		tmp = cursor;
		cursor = cursor->next;
		free(tmp->keyword);
		free(tmp->value);
		free(tmp->elem);
		free(tmp);
	}
}
