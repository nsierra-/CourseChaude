/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#!&+#+#+   +#+           */
/*   Created: 2013/12/06 06:27:39 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 02:06:25 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	n;

	if (s1 && s2)
	{
		n = ft_strlen(s1) + ft_strlen(s2);
		s = (char*)malloc(sizeof(char) * (n + 1));
		if (s != NULL)
		{
			*s = '\0';
			s = ft_strcat(s, s1);
			s = ft_strcat(s, s2);
		return (s);
		}
	}
	return (0);
}
