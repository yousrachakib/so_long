/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_up_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:39:53 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/07 23:03:18 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_w(t_list   *info)
{
    info->map[info->player1.y][info->player1.x] = '0';
    info->map[info->player1.y - 1][info->player1.x] = 'P';
    mlx_clear_window(info->mlx, info->mlx_win);
    info->player1.y -= 1;
    add_to_window(info);   
}
void    move_up(t_list *info)
{
    if (info->map[info->player1.y - 1][info->player1.x] != '1' \
        && info->map[info->player1.y - 1][info->player1.x] != 'E')
    {
         move_w(info);       
    }
}

void    move_s(t_list   *info)
{
    info->map[info->player1.y][info->player1.x] = '0';
    info->map[info->player1.y + 1][info->player1.x] = 'P';
    mlx_clear_window(info->mlx, info->mlx_win);
    info->player1.y += 1;
    add_to_window(info);   
}
void    move_down(t_list *info)
{
    if (info->map[info->player1.y + 1][info->player1.x] != '1' \
        && info->map[info->player1.y + 1][info->player1.x] != 'E')
    {
         move_s(info);       
    }
}