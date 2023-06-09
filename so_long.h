/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:19:57 by yochakib          #+#    #+#             */
/*   Updated: 2023/04/11 20:23:21 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <string.h>

typedef struct t_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct t_list
{
	t_pos	player1;
	t_pos	exit1;
	int		moves;
	int		coins_counter;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	void	*collect;
	void	*exit;
	void	*player;
	void	*space;
	void	*wall;
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	*map1d;
}	t_list;

void	ft_putchar_fd(char c, int fd);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr_fd(int n, int fd);
void	init_args(t_list *info);
void	check_emptyline(t_list *info);
int		quit(t_list *info);
int		my_free(char **res);
void	move_up(t_list *info);
void	move_down(t_list *info);
void	move_left(t_list *info);
int		key_code(int key_code, t_list *info);
void	move_right(t_list *info);
void	check_valid_path(t_list *info);
void	check_map_parsing(t_list *info);
void	check_path(t_list *info, int base);
void	get_cordinates(t_list *info);
int		check_exist(char **map, int base);
int		add_to_window(t_list *info);
void	put_to_window(char **map, t_list *info, int i, int j);
void	pointer_image(t_list *info);
int		calcul_height(int y, char **map);
int		calcul_width(int x, char **map);
void	creat_window(char **map, t_list *info);
void	check_elements(char *map);
void	check_wall2(char *map);
void	check_wall(t_list *info);
void	ft_putstr_fd(char *s, int fd);
int		checkerror(int ac, char **av);
int		my_strlen(char *s);
int		tab_len(char **tab);
void	check_duplicate(char *map);
void	check_map(char *map);
void	check_ifrectangular(char **map_2D);
int		newline_pos(char *s, int pos);
char	**ft_split(char *s, char c);

#endif
