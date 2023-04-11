/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:31:19 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/11 18:09:40 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	detect_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (-1);
}

char	*ft_line(char *res)
{
	char	*line;
	int		len;

	if (res[0] == '\0')
		return (NULL);
	len = 0;
	while (res[len] != '\n' && res[len] != '\0')
		len++;
	if (res[len] == '\n')
		len++;
	line = ft_substr(res, 0, len);
	return (line);
}

char	*new_res(char *res)
{
	char	*tmp;
	size_t	start;
	int		i;

	start = 0;
	i = 0;
	while (res[start] != '\n' && res[start] != '\0')
		start++;
	if (res[start] == '\n')
		start++;
	if (res[start] == '\0')
	{
		free(res);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(res) - start + 1));
	if (!tmp)
		return (NULL);
	while (res[start])
		tmp[i++] = res[start++];
	tmp[i] = '\0';
	free(res);
	return (tmp);
}

char	*ft_read(int fd, char *res)
{
	char	*buff;
	int		n;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!res)
		res = ft_strdup("");
	n = 1;
	while (n != 0 && detect_newline(res) == -1)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n < 0)
		{
			free(res);
			free(buff);
			return (NULL);
		}
		buff[n] = '\0';
		res = ft_strjoin(res, buff);
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	res = ft_read(fd, res);
	if (!res)
		return (NULL);
	line = ft_line(res);
	res = new_res(res);
	return (line);
}
