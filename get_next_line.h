/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:13:17 by ichouare          #+#    #+#             */
/*   Updated: 2022/11/06 14:38:47 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	found_nl(const char *str, int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t number, size_t size);
char	*get_next_line(int fd);
#endif