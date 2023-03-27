/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:19:57 by yochakib          #+#    #+#             */
/*   Updated: 2023/03/27 15:35:28 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct t_list
{
	int     x;
	int     y;
	void    *mlx;
    void    *mlx_win;
}   t_list;

int	calcul_height(int y,char **map);
int	calcul_width(int x,char **map);
void	creat_window(char **map, t_list *info);
void	check_elements(char *map);
void	check_wall2(char *map);
void	check_wall(char	*map);
void	ft_putstr_fd(char *s, int fd);
int		checkerror(int ac, char **av);
int		my_strlen(const char *s);
void	check_duplicate(char *map);
void	check_map(char *map);
void	check_ifrectangular(char *map);
int		newline_pos(char *s, int pos);
char	**ft_split(char const *s, char c);

#endif
