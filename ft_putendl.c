/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:28:16 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/15 20:29:46 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <unistd.h>

static size_t		ft_strlen(const char *s)
{
	char	*save;

	save = (char*)s;
	while (*save != '\0')
		++save;
	return (save - s);
}

void				*ft_putendl(const char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	return (NULL);
}
