/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 21:20:47 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/14 02:09:17 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 1024

int		get_next_line(int const fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
char	*ft_strcat(char *s1, const char *s2);
void	ft_strend(char **str);

#endif
