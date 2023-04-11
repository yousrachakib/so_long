/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_right_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:16:03 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/11 20:29:40 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_d(t_list *info)
{
	if (info->map[info->player1.y][info->player1.x + 1] == 'E' \
	&& info->coins_counter)
		return ;
	info->map[info->player1.y][info->player1.x] = '0';
	if (info->map[info->player1.y][info->player1.x + 1] == 'C')
		info->coins_counter -= 1;
	if (info->map[info->player1.y][info->player1.x + 1] == 'E' \
	&& info->coins_counter == 0)
	{
		ft_putstr_fd("You WIN\n", 1);
		mlx_destroy_window(info->mlx, info->mlx_win);
		exit (0);
	}
	info->map[info->player1.y][info->player1.x + 1] = 'P';
	info->moves += 1;
	ft_putstr_fd(">>>>MOVE NUMBER :", 1);
	ft_putnbr_fd(info->moves, 1);
	ft_putstr_fd("\n", 1);
	mlx_clear_window(info->mlx, info->mlx_win);
	info->player1.x += 1;
	add_to_window(info);
}

void	move_right(t_list *info)
{
	if (info->map[info->player1.y][info->player1.x + 1] != '1')
		move_d(info);
}

void	move_a(t_list *info)
{
	if (info->map[info->player1.y][info->player1.x - 1] == 'E' \
	&& info->coins_counter)
		return ;
	info->map[info->player1.y][info->player1.x] = '0';
	if (info->map[info->player1.y][info->player1.x - 1] == 'C')
		info->coins_counter -= 1;
	if (info->map[info->player1.y][info->player1.x - 1] == 'E' \
	&& info->coins_counter == 0)
	{
		ft_putstr_fd("You WIN\n", 1);
		mlx_destroy_window(info->mlx, info->mlx_win);
		exit (0);
	}
	info->map[info->player1.y][info->player1.x - 1] = 'P';
	info->moves += 1;
	ft_putstr_fd(">>>>MOVE NUMBER :", 1);
	ft_putnbr_fd(info->moves, 1);
	ft_putstr_fd("\n", 1);
	mlx_clear_window(info->mlx, info->mlx_win);
	info->player1.x -= 1;
	add_to_window(info);
}

void	move_left(t_list *info)
{
	if (info->map[info->player1.y][info->player1.x - 1] != '1')
		move_a(info);
}
