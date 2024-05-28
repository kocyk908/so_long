/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:02:02 by lkoc              #+#    #+#             */
/*   Updated: 2024/05/13 12:02:02 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	place_player(t_complete *game, int height, int width)
{
	void	*player_image;

	if (game->last_move == 'w')
		player_image = game->player_up;
	else if (game->last_move == 's')
		player_image = game->player_down;
	else if (game->last_move == 'a')
		player_image = game->player_left;
	else if (game->last_move == 'd')
		player_image = game->player_right;
	else
		player_image = game->player;
	mlx_put_image_to_window(game->mlxptr, game->winptr,
		player_image, width * 40, height * 40);
	game->player_y = height;
	game->player_x = width;
}

static void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxptr,
		game->winptr, game->collectable, width * 40, height * 40);
	game->collectables++;
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxptr,
			"prints/stone.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlxptr,
			"prints/dirt.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxptr,
			"prints/monkey.xpm", &i, &j);
	game->exit_covered = mlx_xpm_file_to_image(game->mlxptr,
			"prints/ladder_covered.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxptr,
			"prints/ladder.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxptr,
			"prints/desire.xpm", &i, &j);
	game->player_up = mlx_xpm_file_to_image(game->mlxptr,
			"prints/monkey_w.xpm", &i, &j);
	game->player_down = mlx_xpm_file_to_image(game->mlxptr,
			"prints/monkey_s.xpm", &i, &j);
	game->player_left = mlx_xpm_file_to_image(game->mlxptr,
			"prints/monkey_a.xpm", &i, &j);
	game->player_right = mlx_xpm_file_to_image(game->mlxptr,
			"prints/monkey_d.xpm", &i, &j);
}

static void	draw_element(t_complete *game, int height, int width)
{
	char	elem;
	int		x;
	int		y;

	elem = game->map[height][width];
	set_variables(&x, &y, height, width);
	if (elem == '1')
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->wall, x, y);
	else if (elem == 'C')
		place_collectable(game, height, width);
	else if (elem == 'P')
		place_player(game, height, width);
	else if (elem == 'E')
	{
		if (game->collectables > 0)
			mlx_put_image_to_window(game->mlxptr,
				game->winptr, game->exit_covered, x, y);
		else
			mlx_put_image_to_window(game->mlxptr,
				game->winptr, game->exit, x, y);
	}
	else if (elem == '0')
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->floor, x, y);
}

void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			draw_element(game, height, width);
			width++;
		}
		height++;
	}
	display_stats(game);
}
