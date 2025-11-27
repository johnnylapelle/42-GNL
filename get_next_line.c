/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacossi <jvacossi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:01:59 by jvacossi          #+#    #+#             */
/*   Updated: 2025/11/27 09:28:11 by jvacossi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*stash;
	int			pos;
	char		*res;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	stash = NULL;
	stash = ft_strjoin(stash, buffer);
	pos = ft_isendl(stash);
	if (pos < 0)
	{
		stash = ft_read_to_stash(buffer, stash, fd);
		if (stash == NULL || *stash == '\0')
		{
			free(stash);
			return (NULL);
		}
	}
	res = ft_extract(stash);
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
		return (ft_substr(stash, 0, ft_strlen(stash)));
}

void	ft_clean(char *stash, char *buffer)
{
	int		pos;

	pos = ft_isendl(stash);
	if (pos == -1)
		buffer[0] = '\0';
	else if (pos + 1 <= ft_strlen(stash))
		ft_memmove(buffer, &stash[pos + 1], ft_strlen(stash) - (pos + 1) + 1);
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
		{
			free(stash);
			return (NULL);
		}
		else if (bytes == 0)
			return (stash);
		buffer[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		free(tmp);
		if (!stash)
			return (NULL);
		pos = ft_isendl(stash);
	}
	return (stash);
}

int	ft_isendl(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// int	main(int argc, char *argv[])
// {
// 	if (argc > 2)
// 		return (-1);
// 	int fd = open(argv[1], O_RDONLY);
// 	// int fd = -1;
// 	char	*str;
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	close(fd);
// 	fd = open(argv[1], O_RDONLY);
// 	printf("new\n");
// 	while ((str = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	close(fd);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// }
