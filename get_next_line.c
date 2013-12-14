/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 21:20:02 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 01:48:13 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		new_line(char **lastc, char **line)
{
	char		*tmp;
	size_t		i;

	i = 0;
	while ((*lastc)[i] != '\n')
		i++;
	*line = ft_strsub(*lastc, 0, i);
	tmp = *lastc;
	*lastc = ft_strsub(*lastc, i + 1, ft_strlen(*lastc) - i);
	free(tmp);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char	*lastc;
	char		*tmp;
	int			read_res;
	char		buff[BUFF_SIZE + 1] = {'\0'};

	lastc = (lastc) ? lastc : ft_strnew(1);
	if (ft_strchr(lastc, '\n') && (new_line(&lastc, line)))
		return (1);
	if ((read_res = read(fd, buff, BUFF_SIZE)) > 0 && (tmp = lastc))
	{
		lastc = ft_strjoin(lastc, buff);
		free(tmp);
		return (get_next_line(fd, line));
	}
	if (read_res == 0)
	{
		if (*lastc && (*line = lastc))
		{
			lastc = NULL;
			return (1);
		}
		return (0);
	}
	return (-1);
}
