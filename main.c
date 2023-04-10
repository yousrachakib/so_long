/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:34:21 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/10 22:43:17 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	part2(t_list *info, char *map)
{
	char	**map2d;

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
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
		// printf("%s\n", line);
		if (!line)
			break ;
		if (my_strlen(line) <= 1)
		{
			printf("ERROR empty line\n");
			exit (1);
		}
		if (!strcmp(line, "\n")) // change to ft_strcmp
		{
			printf("errrrrrrrrrrrror\n");
			exit(1);
		}
	}
	part2(info, map);
}
