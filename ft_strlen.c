/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#!&+#+#+   +#+           */
/*   Created: 2013/12/06 06:27:39 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 02:06:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	char	*save;

	save = (char*)s;
	while (*save != '\0')
	{
		++save;
	}
	return (save - s);
}
