/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacossi <jvacossi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:48:06 by vacossin          #+#    #+#             */
/*   Updated: 2025/11/23 17:31:50by jvacossi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			indexe;
	char		*stash;
	char		*res;

	stash = NULL;
	stash = ft_strjoin(NULL, buffer);
	if (!stash)
		return (NULL);
	indexe = ft_isendl(stash);
	if (indexe < 0)
	{
		stash = ft_read_and_join(buffer, stash, fd, indexe);
		if (!stash)
			return (NULL);
	}
	indexe = ft_isendl(stash);
	if (indexe + 1 < ft_strlen(stash))
		ft_memmove(buffer, &stash[indexe + 1], ft_strlen(stash) - (indexe + 1) + 1);
	else
		buffer[0] = '\0';
	res = ft_substr(stash, 0, indexe + 1);
	free(stash);
	return (res);
}

char	*ft_read_and_join(char *buffer, char *stash, int fd, int indexe)
{
	int		bytes_read;
	char	*res;

	while (indexe < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read == 0 && ft_strlen(stash))
				return (ft_buffermove(stash, buffer, indexe, bytes_read));
			free(stash);
			return(NULL);
		}
		buffer[bytes_read] = '\0';
		res = stash;
		stash = ft_strjoin(stash, buffer);
		free(res);
		if (!stash)
			return (NULL);
		indexe = ft_isendl(stash);
	}
	return (stash);
}

char	*ft_buffermove(char *stash, char *buffer, int indexe, int bytes_read)
{
	char	*res;

	res = ft_substr(stash, 0, indexe + 1);
	free(stash);
	return (res);
}

int	ft_isendl(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
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

int	main(int argc, char *argv[])
{
	if (argc > 2)
		return (-1);
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	char	*str;
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	free(str);
	close(fd);
}
