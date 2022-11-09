/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:21:00 by ichouare          #+#    #+#             */
/*   Updated: 2022/11/06 13:57:04 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//lenght function 
size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//join function 
static char	*strimplement(char *str, char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		str[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	char	*arr;

	if (!s1 && !s2)
		return (NULL);
	str = NULL;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	arr = strimplement(str, s1, s2);
	free(s1);
	return (arr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	int		size;

	arr = NULL;
	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) > len)
		size = len;
	else
		size = ft_strlen(s) - start;
	arr = (char *)(malloc(sizeof(char) * (size + 1)));
	if (!arr)
		return (NULL);
	while (size--)
	{
		*(arr + i) = *(s + start + i);
		i++;
	}
	arr[i] = '\0';
	s = NULL;
	return (arr);
}

//fucntion strchr for '\n
char	*ft_strchr(char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return (s);
}
