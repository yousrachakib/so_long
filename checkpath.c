/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:42:56 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/13 20:12:54 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(char **map, int y, int x, int base)
{
	if (map[y][x] != '0' && map[y][x] != 'P' && map[y][x] != base
		&& map[y][x] != 'C')
		return ;
	map[y][x] = 'X';
	floodfill(map, y, x + 1, base);
	floodfill(map, y, x - 1, base);
	floodfill(map, y + 1, x, base);
	floodfill(map, y - 1, x, base);
}

int	check_exist(char **map, int base)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == base)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_path(t_list *info, int base)
{
	char	**map;

	map = ft_split(info->map1d, '\n');
	floodfill(map, info->player1.y, info->player1.x, base);
	if (base == 'C')
	{
		if (check_exist(map, base))
		{
			my_free(map);
			ft_putstr_fd("ERROR!There is no valid path \
			to catch all collectibles.\n", 2);
			exit (1);
		}
	}
	if (base == 'E')
	{
		if (check_exist(map, base))
		{
			my_free(map);
			ft_putstr_fd("ERROR!There is no valid path to go the exit.\n", 2);
			exit (1);
		}
	}
	my_free(map);
}
