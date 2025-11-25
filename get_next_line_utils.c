/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacossi <jvacossi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:40:24 by jvacossi          #+#    #+#             */
/*   Updated: 2025/11/25 18:04:45 by jvacossi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	int		s1len;
	int		s2len;

	if (!s1 && !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	strjoin = malloc(s1len + s2len + 1);
	if (strjoin == NULL)
		return (NULL);
	ft_strlcpy(strjoin, s1, s1len + 1);
	ft_strlcat(strjoin, s2, s2len + s1len + 1);
	return (strjoin);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlcat(char *dst, char *src, int size)
{
	int	i;
	int	dst_len;

	dst_len = ft_strlen(dst);
	i = 0;
	if (size == 0 || dst_len >= size)
		return (ft_strlen(src) + size);
	if (size > dst_len)
	{
		while (i + dst_len + 1 < size && src[i])
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}

int	ft_strlcpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		if (i < size)
			dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*substr;
	int	i;
	int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (NULL);
	if (s_len - start < len)
		len = s_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

