/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:18:07 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/10 20:14:44 by yochakib         ###   ########.fr       */
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
            if (info->map[i][j] == 'C')
                info->coins_counter += 1;
            j++;
        }
        i++;
    }
}

void    check_map_parsing(t_list *info)
{
    // check_emptyline(info);
    check_elements(info->map1D);
	check_map(info->map1D);
	check_duplicate(info->map1D);
	check_wall(info->map);
}

void check_valid_path(t_list *info)
{
    get_cordinates(info);
    printf("--8--\n");
	check_path(info, 'C');
	check_path(info, 'E');
}