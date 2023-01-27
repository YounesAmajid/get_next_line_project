/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:28:56 by yamajid           #+#    #+#             */
/*   Updated: 2023/01/27 15:17:45 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_line_index(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (ft_strlen(str));
}

char	*ft_free(char **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
	return (*p);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	if ((char) c == '\0')
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*read_save(char *stock, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	while (!(ft_strchr(stock, '\n')))
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (free(buffer), stock);
		if (bytes_read == -1)
			return (free(buffer), free(stock), NULL);
		buffer[bytes_read] = '\0';
		stock = ft_strjoin(stock, buffer);
		free(buffer);
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;
	char		*tmp;
	size_t		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = read_save(stock, fd);
	if (!stock || !*stock)
		return (ft_free (&stock), NULL);
	i = get_line_index(stock);
	line = ft_substr(stock, 0, i);
	if (!line)
		return (ft_free(&stock), NULL);
	tmp = stock;
	if (ft_strlen(tmp))
		stock = ft_substr(&tmp[i], 0, ft_strlen(&tmp[i]));
	else
		stock = NULL;
	free(tmp);
	return (line);
}
