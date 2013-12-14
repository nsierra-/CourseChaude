/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#!&+#+#+   +#+           */
/*   Created: 2013/12/06 06:27:39 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 02:08:08 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*save;

	if(s)
	{
		str = (char*)malloc(sizeof(char) * len);
		if (str != NULL)
		{
			save = str;
			while (start--)
				++s;
			while (len--)
				*str++ = *s++;
			return (save);
		}
		return (0);
	}
	return (NULL);
}
