/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:34:21 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/11 19:58:41 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	part2(t_list *info, char *map)
{
	char	**map2d;

	if (map[my_strlen(map) - 1] == '\n')
	{
		ft_putstr_fd("Error\nEmpty line located at end of map!", 2);
		exit(1);
	}
	info = malloc(sizeof(t_list));
	init_args(info);
	info->map1d = map;
	info->map = ft_split(map, '\n');
	check_map_parsing(info);
	map2d = ft_split(map, '\n');
	check_ifrectangular(map2d);
	check_valid_path(info);
	creat_window(map2d, info);
	my_free(info->map);
	my_free(map2d);
	free(info->map1d);
}

void	lineserror(char *line)
{
	if (!ft_strcmp(line, "\n"))
	{
		ft_putstr_fd("Error\nEmpty line located at beginning of map!", 2);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	char	*line;
	char	*map;
	int		fd;
	t_list	*info;

	info = NULL;
	map = ft_strdup("");
	fd = checkerror(ac, av);
	line = get_next_line(fd);
	lineserror(line);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (my_strlen(line) <= 1)
		{
			ft_putstr_fd("ERROR\n empty line", 2);
			exit (1);
		}
	}
	part2(info, map);
}
