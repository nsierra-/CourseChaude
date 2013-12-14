/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#!&+#+#+   +#+           */
/*   Created: 2013/12/06 06:27:39 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 02:07:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*s;
	char	*save;

	s = (char*)malloc(sizeof(char) * size);
	if (s != NULL)
	{
		save = s;
		while (size--)
			*s++ = '\0';
		*s = '\0';
		return (save);
	}
	return (NULL);
}
