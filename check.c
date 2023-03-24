/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:09:37 by yochakib          #+#    #+#             */
/*   Updated: 2023/03/24 02:45:17 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	checkerror(int ac, char **av)
{
	int	i;
	int	fd;

	if (ac != 2)
	{
		ft_putstr_fd("Error few arguments\n", 2);
		exit (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error file not opened\n", 2);
		exit (1);
	}
	i = my_strlen(av[1]) - 1;
	if (i < 5 || av[1][i] != 'r'
		|| av[1][i -1] != 'e' || av[1][i - 2] != 'b' || av[1][i - 3] != '.')
	{
		ft_putstr_fd("Error wrong filetype\n", 2);
		exit (1);
	}
	return (fd);
}

void	check_duplicate(char *map)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i])
	{
		if (map[i] == 'C' || map[i] == 'P' || map[i] == 'E')
			counter++;
		i++;
	}
	if (counter != 3)
	{
		ft_putstr_fd("Error Map not valide\n", 2);
		exit (1);
	}
}

void	check_map(char *map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map);
	while (i < len)
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == 'C'
			|| map[i] == 'P' || map[i] == 'E' || map[i] == '\n')
			i++;
		else
		{
			ft_putstr_fd("Error invalid map", 2);
			exit (1);
		}
	}
}
