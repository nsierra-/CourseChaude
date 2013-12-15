/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:46:37 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/15 20:47:00 by nsierra-         ###   ########.fr       */
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

void				ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}
