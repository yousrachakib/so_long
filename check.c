/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:09:37 by yochakib          #+#    #+#             */
/*   Updated: 2023/03/23 22:56:53 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int    checkerror(int ac, char **av)
{
    int i;
    int fd;
    if (ac != 2)
    {
	    ft_putstr_fd("Error few arguments\n", 2);
        exit (1);
    }
    fd = open( av[1], O_RDONLY );
    if (fd < 0)
	{
	    ft_putstr_fd("Error file not opened\n", 2);
        exit (1);
    }
    i = my_strlen(av[1]) - 1;
    if ( i < 5 || av[1][i] != 'r' || av[1][i -1] != 'e' || av[1][i - 2] != 'b' || av[1][i - 3] != '.')
    {
	    ft_putstr_fd("Error wrong filetype\n", 2);
        exit (1);
    }
    return (fd);
}