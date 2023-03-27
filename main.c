/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:19:11 by yochakib          #+#    #+#             */
/*   Updated: 2023/03/27 16:11:32 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	init_args(t_list *info)
{
	info->x = 0;
	info->y = 0;
	info->mlx = NULL;
	info->mlx_win = NULL;
}

int	calcul_width(int x,char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	x = i;
	return (x);
}
int	calcul_height(int y,char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
		i++;
	y = i;
	return (y);
}

void	creat_window(char **map, t_list *info)
{
	init_args(info);
	info->y = calcul_height(info->y, map);
	info->x = calcul_width(info->x, map);
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, info->x*50, info->y*50, "so_long");
	mlx_loop(info->mlx);
}
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
	if (i < 4 || av[1][i] != 'r'
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
	char 	**map_2D;
	int		fd;
	t_list	*info;

	map = ft_strdup("");
	fd = checkerror(ac, av);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	info = malloc(sizeof(t_list));
	check_elements(map);
	check_map(map);
	check_duplicate(map);
	check_ifrectangular(map);
	check_wall(map);
	map_2D = ft_split(map, '\n');
	creat_window(map_2D, info);
}
