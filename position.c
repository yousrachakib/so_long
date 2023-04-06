/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:18:07 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/06 17:50:43 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_cordinates(t_list *info)
{
    int i;
    int j;

    i = 0;
    while (info->map[i])
    {
        j = 0;
        while (info->map[i][j])
        {
            if (info->map[i][j] == 'P')
            {
                info->player1.x = j;
                info->player1.y = i;
            }
            if (info->map[i][j] == 'E')
            {
                info->exit1.x = j;
                info->exit1.x = i;
            }
            j++;
        }
        i++;
    }
}

void    check_map_parsing(char  *map)
{
    check_elements(map);
	check_map(map);
	check_duplicate(map);
	check_ifrectangular(map);
	check_wall(map);
}

void check_valid_path(t_list *info)
{
    get_cordinates(info);
	check_path(info, 'C');
	check_path(info, 'E');
}