/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:20:02 by lkoc              #+#    #+#             */
/*   Updated: 2024/05/28 13:22:37 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_point(t_complete *game)
{
	int	line;

	line = 0;
	if (game->winptr)
		mlx_destroy_window(game->mlxptr, game->winptr);
	free(game->mlxptr);
	while (line < game->heightmap - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
		return (0);
	ft_bzero(&game, sizeof(t_complete));
	map_reading(&game, argv);
	check_errors(&game);
	if (!can_reach_exit(&game) || !can_collect_all(&game))
	{
		printf("Invalid path\n");
		exit_point(&game);
	}
	game.mlxptr = mlx_init();
	game.winptr = mlx_new_window(game.mlxptr, (game.widthmap * 40),
			(game.heightmap * 40), "solong");
	place_images_in_game(&game);
	mlx_key_hook(game.winptr, controls_working, &game);
	mlx_hook(game.winptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxptr);
}
