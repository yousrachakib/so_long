/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:49:53 by yochakib          #+#    #+#             */
/*   Updated: 2023/03/25 17:29:03 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	my_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	newline_pos(char *s, int pos)
{
	while (s[pos])
	{
		if (s[pos] == '\n')
			return (pos);
		pos++;
	}
	return (-1);
}

void	check_wall(char	*map)
{
	int	i;
	int	len;
	int	j;

	len = ft_strlen(map) - 1;
	j = 0;
	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if (map[j] == '1')
			j++;
		else
		{
			free(map);
			ft_putstr_fd("Error : map invalid", 2);
			exit (1);
		}
		i++;
	}
	i = len;
	while (map[len] && map[len] != '\n')
	{
		if (map[i] == '1')
			i--;
		else
		{
			free(map);
			ft_putstr_fd("Error : map invalid", 2);
			exit (1);
		}
		len--;
	}
	check_wall2(map);
}
