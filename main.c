/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:19:11 by yochakib          #+#    #+#             */
/*   Updated: 2023/03/25 14:19:30 by yochakib         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	char	*line;
	char	*map;
	int		fd;

	map = ft_strdup("");
	fd = checkerror(ac, av);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	// printf("%s\n", map);
	check_map(map);
	check_duplicate(map);
	check_ifrectangular(map);
	check_wall2(map);
}
