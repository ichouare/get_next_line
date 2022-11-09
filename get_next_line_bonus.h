/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:18:57 by ichouare          #+#    #+#             */
/*   Updated: 2022/11/06 12:58:13 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t number, size_t size);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif