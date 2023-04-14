/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:01:15 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/13 20:27:18 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	pointer_image(t_list	*info)
{
	info->space = mlx_xpm_file_to_image(info->mlx, "image/SPACE.xpm" \
	, &info->img_width, &info->img_height);
	info->player = mlx_xpm_file_to_image(info->mlx, "image/PLAYER.xpm" \
	, &info->img_width, &info->img_height);
	info->collect = mlx_xpm_file_to_image(info->mlx, "image/COINS.xpm" \
	, &info->img_width, &info->img_height);
	info->exit = mlx_xpm_file_to_image(info->mlx, "image/EXIT1.xpm" \
	, &info->img_width, &info->img_height);
	info->wall = mlx_xpm_file_to_image(info->mlx, "image/WALL.xpm" \
	, &info->img_width, &info->img_height);
	if (!info->wall || !info->space || !info->player || !info->collect || \
		!info->exit)
	{
		ft_putstr_fd("Error check XPM files", 2);
		exit (1);
	}
}

int	add_to_window(t_list *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			put_to_window(info->map, info, i, j);
			j += 1;
		}
		i += 1;
	}
	return (0);
}

void	put_to_window(char **map, t_list *info, int i, int j)
{
	if (map[i][j] == 'C')
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->collect, \
		j * 50, i * 50);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->exit, \
		j * 50, i * 50);
	else if (map[i][j] == 'P')
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->player, \
		j * 50, i * 50);
	else if (map[i][j] == '0')
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->space, \
		j * 50, i * 50);
	else if (map[i][j] == '1')
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->wall, \
		j * 50, i * 50);
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
	i = my_strlen(av[1]);
	if (i <= 4 && (av[1][i] != 'r'
		|| av[1][i -1] != 'e' || av[1][i - 2] != 'b' || av[1][i - 3] != '.'))
	{
		ft_putstr_fd("Error wrong filetype\n", 2);
		exit (1);
	}
	return (fd);
}
