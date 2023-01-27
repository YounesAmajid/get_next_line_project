/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:29:09 by yamajid           #+#    #+#             */
/*   Updated: 2023/01/25 18:29:12 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(char *dst, char *src, size_t n)
{
	size_t		i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc((len) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, len);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (s1);
	ptr = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[++j])
		ptr[i + j] = s2[j];
	return (ptr[i + j] = '\0', free(s1), ptr);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	stlen;
	char			*ptr;

	if (str == NULL)
		return (NULL);
	stlen = ft_strlen(str);
	if (start > stlen)
		return (NULL);
	if (len > stlen)
	len = stlen - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] && i < len && start < len)
	{
		ptr[i] = str[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
