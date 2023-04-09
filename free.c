/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:13:44 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/09 22:25:56 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_free(char **res)
{   int i;
    i = 0;
    
	while (res[i])
	{
		free(res[i++]);
	}
	free(res);
	return (0);
}

int	quit(t_list *info)
{
	mlx_destroy_window(info->mlx, info->mlx_win);
	exit(0);
	return (0);
}