/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:18:36 by ichouare          #+#    #+#             */
/*   Updated: 2022/11/06 12:53:10 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*arr;

	arr = NULL;
	arr = (void *)malloc(size * number);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size * number);
	return (arr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p1;

	p1 = s;
	while (n--)
	{
		*p1 = '\0';
		p1++;
	}
}

static int	fnl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*heandler_next_line(char **svr, int fd, char *buffer)
{
	char	*tmp;
	char	*line;

	if (ft_strlen(svr[fd]) == 0 || !svr)
	{
		free(buffer);
		free(svr[fd]);
		svr[fd] = NULL;
		return (NULL);
	}
	if (ft_strchr(svr[fd], '\n'))
	{
		line = ft_substr(svr[fd], 0, fnl(svr[fd]) + 1);
		tmp = svr[fd];
		svr[fd] = ft_substr(svr[fd], fnl(svr[fd]) + 1, ft_strlen(svr[fd]) + 1);
		free(tmp);
	}
	else
	{
		line = ft_substr(svr[fd], 0, ft_strlen(svr[fd]) + 1);
		free(svr[fd]);
		svr[fd] = NULL;
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*svr[10240];
	ssize_t		sz;

	sz = 1;
	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	if (!svr[fd])
		svr[fd] = ft_substr(buffer, 0, 1);
	while (ft_strchr(svr[fd], '\n') == 0 && sz != 0)
	{
		sz = read(fd, buffer, BUFFER_SIZE);
		if (sz <= -1)
		{
			free(buffer);
			free(svr[fd]);
			return (NULL);
		}
		svr[fd] = ft_strjoin(svr[fd], buffer);
		ft_bzero(buffer, ft_strlen(buffer) + 1);
	}
	return (heandler_next_line(svr, fd, buffer));
}
