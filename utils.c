/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:49:53 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/10 19:56:33 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	my_strlen(char *s)
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

void	check_wall(char	**map)
{
	int	i;
	int	len;
	int len2;
	int	j;

	len = tab_len(map) - 1;
	j = 0;
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
		{
			printf("ERROOOOR 1st wall\n");
			exit (1);
		}
		i++;
	}
	i = 0;
	while (map[len][i])
	{
		if (map[len][i] != '1')
		{
			printf("ERROOOOR last wall\n");
			exit (1);
		}
		i++;
	}
	i = 0;
	while (i <= len)
	{
		if (map[i][0] != '1')
		{
			printf("ERROOOOR bord left\n");
			exit (1);
		}
		i++;
	}
	i = 0;
	while (i <= len)
	{
		len2 = my_strlen(map[i]) - 1;
		if (map[i][len2] != '1')
		{
			printf("ERROOOOR bord right\n");
			exit (1);
		}
		i++;
	}
}
