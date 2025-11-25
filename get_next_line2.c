/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacossi <jvacossi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:01:59 by jvacossi          #+#    #+#             */
/*   Updated: 2025/11/25 18:42:29 by jvacossi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Refining the architecture
// Read to stash
// Extract line from stash
// Clean stash

// Helper functions :
// ft_strjoin
	// ft_strlcpy
	// ft_strlcat
// ft_strchr -> custom
// ft_memmove
// ft_strlen

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*stash;
	int			pos;
	char		*res;

	stash = NULL;
	stash = ft_strjoin(stash, buffer);
	pos = ft_isendl(stash);
	if (pos < 0)
		stash = ft_read_to_stash(buffer, stash, fd);
	ft_extract(stash);
	ft_clean(stash, buffer);
	return (res);
}

char	*ft_extract(char *stash)
{
	int	pos;

	pos = ft_isendl(stash);
	if (pos != -1)
		return (ft_substr(stash, 0, pos + 1));
	else
		return (stash);
}

void	ft_clean(char *stash, char *buffer)
{
	int		pos;
	char	*res;

	pos = ft_isendl(stash);
	if (pos + 1 <= ft_strlen(stash))
		ft_memmove(buffer, &stash[pos + 1], ft_strlen(stash) - (pos + 1) + 1);
	else
		buffer[0] = '\0';
	free(stash);
}

char	*ft_read_to_stash(char *buffer, char *stash, int fd)
{
	int		bytes;
	int		pos;
	char	*tmp;

	pos = -1;
	while (pos < 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		else if (bytes == 0)
		// need to join b4 returning stash
			return (stash);
		buffer[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		free(tmp);
		pos = ft_isendl(stash);
	}
	return (stash);
}

int	ft_isendl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
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
	// free(str);
	close(fd);
}
