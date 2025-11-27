/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacossi <jvacossi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:55:31 by jvacossi          #+#    #+#             */
/*   Updated: 2025/11/27 08:28:04 by jvacossi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_strlcat(char *dst, char *src, int size);
char	*ft_substr(char *s, int start, int len);
void	*ft_memmove(void *dest, void *src, int n);
char	*ft_extract(char *stash);
void	ft_clean(char *stash, char *buffer);
int		ft_isendl(char *stash);
char	*ft_read_to_stash(char *buffer, char *stash, int fd);

#endif
