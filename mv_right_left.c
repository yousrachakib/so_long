/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_right_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:16:03 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/07 21:38:48 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_d(t_list   *info)
{
    info->map[info->player1.y][info->player1.x] = '0';
    info->map[info->player1.y][info->player1.x + 1] = 'P';
    mlx_clear_window(info->mlx, info->mlx_win);
    info->player1.x += 1;
    add_to_window(info);   
}

void    move_right(t_list *info)
{
    if (info->map[info->player1.y][info->player1.x + 1] != '1' \
        && info->map[info->player1.y][info->player1.x + 1] != 'E')
    {
         move_d(info);       
    }
}

void    move_a(t_list   *info)
{
    info->map[info->player1.y][info->player1.x] = '0';
    info->map[info->player1.y][info->player1.x - 1] = 'P';
    mlx_clear_window(info->mlx, info->mlx_win);
    info->player1.x -= 1;
    add_to_window(info);   
}

void    move_left(t_list *info)
{
    if (info->map[info->player1.y][info->player1.x - 1] != '1' \
        && info->map[info->player1.y][info->player1.x - 1] != 'E')
    {
         move_a(info);       
    }
}