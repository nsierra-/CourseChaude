/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_race.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:34:20 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 03:18:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOT_RACE_H
# define HOT_RACE_H
# define ONE 1
# define TWO 2

typedef struct		s_elem
{
	char			*keyword;
	char			*value;
	struct s_elem	*next;
}					t_elem;

int		get_next_line(int const fd, char **line);
int		ft_strcmp(const char *s1, const char *s2);

#endif /* !HOT_RACE_H */
