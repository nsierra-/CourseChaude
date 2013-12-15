/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:17:50 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/15 21:03:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# define HASH_TABLE_SIZE 4194304
# define ELEM elem[hashich]
# include <stddef.h>

typedef const unsigned int	t_cui;

typedef struct			s_elem
{
	char				*keyword;
	char				*value;
	struct s_elem		*next;
}						t_elem;

typedef struct 			s_to_free
{
	void				*keyword;
	void				*value;
	void				*elem;
	struct s_to_free	*next;
}						t_to_free;

void					*ft_putendl(const char *s);
size_t					ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);
void					ft_putstr(const char *s);
t_elem					*ft_pop_elem(t_elem *elem, char *line);
unsigned int			ft_hashich(char *line);
void					search_keywords(t_elem **elem);
void					free_the_slaves(t_to_free *to_free);

#endif /* !HOTRACE_H */
