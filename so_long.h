/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:19:57 by yochakib          #+#    #+#             */
/*   Updated: 2023/03/25 17:09:21 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG
# define SO_LONG

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

#endif
