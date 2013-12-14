/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 23:26:19 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 09:55:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hot_race.h"
#include <stddef.h>

void	*ft_putendl(const char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
	return (NULL);
}
