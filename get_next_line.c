/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacossi <jvacossi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:48:06 by vacossin          #+#    #+#             */
/*   Updated: 2025/11/22 21:24:13 by jvacossi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*stash;
	char		*res;
	int			index;

	stash = malloc(BUFFER_SIZE);
	if (stash == NULL)
		return (NULL);
	stash = ft_strjoin(stash, buffer);
	index = ft_isendl(stash);
	// printf("stash = %s", stash);
	while (index < 0)
	{
		if (read(fd, buffer, BUFFER_SIZE) == 0)
			return (NULL);
		stash = ft_strjoin(stash, buffer);
		index = ft_isendl(stash);
	}
	res = ft_substr(stash, 0, index);
	index = ft_isendl(buffer);
	ft_memmove(buffer, &buffer[index + 1], ft_strlen(buffer) - (index + 1));
	return (res);
}

int	ft_isendl(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	if (argc > 2)
		return (-1);
	int fd = open(argv[1], O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}
