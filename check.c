/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:09:37 by yochakib          #+#    #+#             */
/*   Updated: 2023/03/27 16:16:17 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	check_duplicate(char *map)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i])
	{
		if (map[i] == 'P' || map[i] == 'E')
			counter++;
		i++;
	}
	if (counter != 2)
	{
		ft_putstr_fd("Error Map not valide\n", 2);
		exit (1);
	}
}

void	check_elements(char *map)
{
	int	i;
	int	counter;
	int	counter1;
	int	counter2;

	i = 0;
	counter = 0;
	counter1 = 0;
	counter2 = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			counter++;
		if (map[i] == 'E')
			counter1++;
		if (map[i] == 'C')
			counter2++;
		i++;
	}
	if (counter != 1 && counter1 != 1 && counter2 >= 1)
	{
		free(map);
		ft_putstr_fd("Error invalid map", 2);
		exit (1);
	}
}

void	check_map(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == 'C'
			|| map[i] == 'P' || map[i] == 'E' || map[i] == '\n')
			i++;
		else
		{
			free(map);
			ft_putstr_fd("Error invalid map", 2);
			exit (1);
		}
	}
}

void	check_ifrectangular(char *map)
{
	int	i;
	int	line_len;
	int	max_line_len;

	i = 0;
	line_len = 0;
	max_line_len = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (line_len > max_line_len)
				max_line_len = line_len;
			line_len = 0;
		}
		else
			line_len++;
		i++;
	}
	if (max_line_len != line_len)
	{
		free(map);
		ft_putstr_fd("Error : map not rectangular", 2);
		exit (1);
	}
}

void	check_wall2(char *map)
{
	int	pos;
	int	i;
	int	start;

	start = 0;
	i = 0;
	while (*map)
	{
		pos = newline_pos(map, start);
		if (map[pos - 1] != '1' && map[pos + 1] != '1' && pos != -1)
		{
			free(map);
			ft_putstr_fd("Error : map invalid", 2);
			exit (1);
		}
		start = pos;
		map++;
	}
}