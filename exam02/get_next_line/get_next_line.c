/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:11:05 by brsantsc          #+#    #+#             */
/*   Updated: 2024/07/04 14:59:41 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, const char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}

char	*ft_strdup(const char *src)
{
	size_t	len = ft_strlen(src) + 1;
	char	*dest = malloc(len);

	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

char	*ft_strjoin(char *str1, char const *str2)
{
	size_t	str1_len = ft_strlen(str1);
	size_t	str2_len = ft_strlen(str2);
	char	*join = malloc((str1_len + str2_len + 1));

	if (!str1 || !str2)
		return (NULL);
	if (!join)
		return (NULL);
	ft_strcpy(join, str1);
	ft_strcpy(join, str2);
	free(str1);
	return (join);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char	*line;
	char	*newline;
	int	read_bytes;
	int	to_copy;

	line = ft_strdup(buff);
	while (!(newline = ft_strchr(line, '\n')) && (read_bytes = read(fd, buff, BUFFER_SIZE)))
	{
		buff[read_bytes] = '\0';
		line = ft_strjoin(line, buff);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strcpy(buff, newline + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		buff[0] = '\0';
	}
	line[to_copy] = '\0';
	return (line);
}
