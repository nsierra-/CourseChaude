/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#!&+#+#+   +#+           */
/*   Created: 2013/12/06 06:27:39 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 02:09:35 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*save;

	save = s1;
	ft_strend(&save);
	while(*s2 != '\0')
	{
		*save = *s2;
		++save;
		++s2;
	}
	*save = '\0';
	return (s1);
}
