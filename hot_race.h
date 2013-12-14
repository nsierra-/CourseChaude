/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_race.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:34:20 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 08:43:31 by nsierra-         ###   ########.fr       */
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

t_elem	*get_elem(void);
t_elem	*search_keyword(t_elem *lst_elem);
int		free_the_slaves(t_elem *lst_elem);
int		get_next_line(int const fd, char **line);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putendl(const char *s);
void	ft_putstr(const char *s);
void	ft_putchar(char c);

#endif /* !HOT_RACE_H */
