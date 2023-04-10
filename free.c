/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:13:44 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/10 20:06:35 by yochakib         ###   ########.fr       */
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

int tab_len(char **tab)
{
	int i;
	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

void	check_emptyline(t_list *info)
{
	int i;
	int	len;

	i = 0;
	len = tab_len(info->map);
	while (i < len)
	{
		printf("%c\n", info->map[i][0]);
		if (info->map[i][0] == '\0')
		{
			printf("ERROR EMPTY LINE\n");
			exit (1);
		}
		i++;
	}
}
