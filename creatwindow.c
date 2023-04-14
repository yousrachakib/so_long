/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatwindow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:19:11 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/13 20:25:32 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	init_args(t_list *info)
{
	info->coins_counter = 0;
	info->img_height = 0;
	info->img_width = 0;
	info->moves = 0;
	info->x = 0;
	info->y = 0;
	info->exit = NULL;
	info->player = NULL;
	info->collect = NULL;
	info->space = NULL;
	info->wall = NULL;
	info->img = NULL;
	info->mlx = NULL;
	info->mlx_win = NULL;
	info->map = NULL;
	info->map1d = NULL;
}

int	calcul_width(int x, char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	x = i;
	return (x);
}

int	calcul_height(int y, char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	y = i;
	return (y);
}

int	key_code(int key_code, t_list *info)
{
	if (key_code == 124 || key_code == 2)
		move_right(info);
	if (key_code == 123 || key_code == 0)
		move_left(info);
	if (key_code == 125 || key_code == 1)
		move_down(info);
	if (key_code == 126 || key_code == 13)
		move_up(info);
	if (key_code == 53)
		quit(info);
	return (0);
}

void	creat_window(char **map, t_list *info)
{
	info->y = calcul_height(info->y, map);
	info->x = calcul_width(info->x, map);
	info->mlx = mlx_init();
	pointer_image(info);
	info->mlx_win = mlx_new_window(info->mlx, info->x * 50, \
	info->y * 50, "so_long");
	mlx_loop_hook(info->mlx, &add_to_window, info);
	mlx_hook(info->mlx_win, 2, 0, &key_code, info);
	mlx_hook(info->mlx_win, 17, 0, &quit, info);
	mlx_loop(info->mlx);
}
