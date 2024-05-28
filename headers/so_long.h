/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:02:35 by lkoc              #+#    #+#             */
/*   Updated: 2024/05/13 12:02:37 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		coincount;
	int		exitcount;
	int		player_x;
	int		player_y;
	int		steps;
	int		collectables;
	int		collect_count;

	char	**map;
	char	last_move;

	void	*mlxptr;
	void	*winptr;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*exit_covered;
	void	*collectable;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	int		start_x;
	int		start_y;
}	t_complete;

int		exit_point(t_complete *game);
int		map_reading(t_complete *game, char **argv);
int		controls_working(int command, t_complete *game);
int		proper_move(t_complete *game, int i, int j);
void	adding_in_graphics(t_complete *game);
void	display_stats(t_complete *game);
void	place_images_in_game(t_complete *game);
void	check_errors(t_complete *game);
void	set_variables(int *x, int *y, int height, int width);
int		horizontalwall(t_complete *game);
int		verticalwall(t_complete *game);
void	if_walls(t_complete *game);
void	count_checker(t_complete *game, int height, int width);
int		can_reach_exit(t_complete *game);
int		can_collect_all(t_complete *game);
void	set_zeros(int *x, int *y, int *z);
bool	valid_move(char **map, bool **visited, int x, int y);
bool	valid_move_coll(char **map, bool **visited, int x, int y);
void	initialize_directions(int directions[4][2]);

#endif
