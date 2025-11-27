/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacossi <jvacossi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:01:59 by jvacossi          #+#    #+#             */
/*   Updated: 2025/11/27 14:57:26 by jvacossi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	char		*stash;
	int			pos;
	char		*res;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	stash = NULL;
	stash = ft_strjoin(stash, buffer[fd]);
	pos = ft_isendl(stash);
	if (pos < 0)
	{
		stash = ft_read_to_stash(buffer[fd], stash, fd);
		if (stash == NULL || *stash == '\0')
		{
			free(stash);
			return (NULL);
		}
	}
	res = ft_extract(stash);
	ft_move_and_clean(stash, buffer[fd]);
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

void	ft_move_and_clean(char *stash, char *buffer)
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
// 	if (argc > 3)
// 		return (-1);
// 	int fd = open(argv[1], O_RDONLY);
// 	int fd2 = open(argv[2], O_RDONLY);
// 	char	*str;
// 	char	*str2;
// 	while ((str = get_next_line(fd))
// != NULL && (str2 = get_next_line(fd2)) != NULL)
// 	{
// 		printf("--- FD 1 ---");
// 		printf("%s", str);
// 		free(str);
// 		printf("--- FD 2 ---");
// 		printf("%s", str2);
// 		free(str2);
// 	}
// 	close(fd);
// 	close(fd2);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// }
