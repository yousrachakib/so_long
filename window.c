/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:01:15 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/03 22:01:41 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    pointer_image(t_list    *info)
{
    int x;
    // (void)info;
    // info->space = mlx_xpm_file_to_image(info->mlx, "image/SPACE.xpm", &info->img_width, &info->img_height);
    // if (!info->space)
    //     exit (1);
    // info->player = mlx_xpm_file_to_image(info->mlx, "image/PLAYER.xpm", &info->img_width, &info->img_height);
    // if (!info->player)
    //     exit (1);
    info->collect = mlx_xpm_file_to_image(info->mlx, "image/COINS.xpm", &x, &x);
    if (!info->collect)
        exit (1);
    // info->exit = mlx_xpm_file_to_image(info->mlx, "image/EXIT.xpm", &info->img_width, &info->img_height);
    // if (!info->exit)
    //     exit (1);
    // info->wall = mlx_xpm_file_to_image(info->mlx, "image/WALL.xpm", &info->img_width, &info->img_height);
    // if (!info->wall)
    //     exit (1);
}

void    add_image_to_win(char **map, t_list *info)
{
    int i;
    int j;
    char c;
    (void)info;

    i = 0;
    while (i < info->y)
    {
        j = 0;
        while(j < info->x)
        {
            if(map[i][j] == 'C')
                mlx_put_image_to_window(info->mlx, info->mlx_win, info->collect,info->img_width , info->img_height);
            j++;
        }
        i++;
    }
}