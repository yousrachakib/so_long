/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:01:15 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/04 22:24:25 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    pointer_image(t_list    *info)
{
    info->space = mlx_xpm_file_to_image(info->mlx, "image/SPACE.xpm", &info->img_width, &info->img_height);
    if (!info->space)
        exit (1);
    info->player = mlx_xpm_file_to_image(info->mlx, "image/PLAYER.xpm", &info->img_width, &info->img_height);
    if (!info->player)
        exit (1);
    info->collect = mlx_xpm_file_to_image(info->mlx, "image/COINS.xpm", &info->img_width, &info->img_height);
    if (!info->collect)
        exit (1);
    info->exit = mlx_xpm_file_to_image(info->mlx, "image/EXIT1.xpm", &info->img_width, &info->img_height);
    if (!info->exit)
        exit (1);
    info->wall = mlx_xpm_file_to_image(info->mlx, "image/WALL.xpm", &info->img_width, &info->img_height);
    if (!info->wall)
        exit (1);
}

void    add_to_window(char **map, t_list *info)
{
    int i;
    int j;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            put_to_window(map, info, i, j);
            j += 1;
        }
        i += 1;
    }
}

void    put_to_window(char **map, t_list *info,int i, int j)
{
    if(map[i][j] == 'C')
        mlx_put_image_to_window(info->mlx, info->mlx_win, info->collect,j *50, i *50);
    else if(map[i][j] == 'E')
        mlx_put_image_to_window(info->mlx, info->mlx_win, info->exit, j *50, i *50);
    else if(map[i][j] == 'P')
        mlx_put_image_to_window(info->mlx, info->mlx_win, info->player, j *50, i *50);
    else if(map[i][j] == '0')
        mlx_put_image_to_window(info->mlx, info->mlx_win, info->space, j *50, i *50);
    else if(map[i][j] == '1')
        mlx_put_image_to_window(info->mlx, info->mlx_win, info->wall, j *50, i *50);
}