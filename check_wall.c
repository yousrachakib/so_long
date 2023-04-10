/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:44:59 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/10 22:05:41 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	part1(t_list *info)
{
	int	i;

	i = 0;
	while (info->map[0][i])
	{
		if (info->map[0][i] != '1')
		{
			printf("ERROOOOR 1st wall\n");
			exit (1);
		}
		i++;
	}
}

void	part02(t_list *info)
{
	int	i;
	int	len;

	i = 0;
	len = tab_len(info->map) - 1;
	while (info->map[len][i])
	{
		if (info->map[len][i] != '1')
		{
			printf("ERROOOOR last wall\n");
			exit (1);
		}
		i++;
	}
}

void	part3(t_list *info)
{
	int	i;
	int	len;

	len = tab_len(info->map) - 1;
	i = 0;
	while (i <= len)
	{
		if (info->map[i][0] != '1')
		{
			printf("ERROOOOR bord left\n");
			exit (1);
		}
		i++;
	}
}

void	check_wall(t_list *info)
{
	int	i;
	int	len;
	int	len2;

	i = 0;
	len = tab_len(info->map) - 1;
	part1(info);
	part02(info);
	part3(info);
	while (i <= len)
	{
		len2 = my_strlen(info->map[i]) - 1;
		if (info->map[i][len2] != '1')
		{
			printf("ERROOOOR bord right\n");
			exit (1);
		}
		i++;
	}
}
