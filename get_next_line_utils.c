/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacossi <jvacossi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:40:24 by jvacossi          #+#    #+#             */
/*   Updated: 2025/11/27 08:42:02 by jvacossi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		s2len;
	int		size;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	s2len = ft_strlen(s2);
	res = malloc(ft_strlen(s1) + s2len + 1);
	if (res == NULL)
		return (NULL);
	size = ft_strlen(s1) + 1;
	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		if (i < size)
			res[i] = '\0';
	}
	ft_strlcat(res, s2, s2len + ft_strlen(s1) + 1);
	return (res);
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

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		i;
	int		s_len;

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

void	*ft_memmove(void *dest, void *src, int n)
{
	int				i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest < src)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			d[i] = s[i];
	}
	return (dest);
}
