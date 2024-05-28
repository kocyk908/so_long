/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:22:47 by lkoc              #+#    #+#             */
/*   Updated: 2024/05/13 16:22:48 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_stats(t_complete *game)
{
	char	*steps;
	char	msg[256];
	char	*info;

	info = "Exit is open now!";
	steps = ft_itoa(game->steps);
	ft_strlcpy(msg, "Steps taken: ", sizeof(msg));
	ft_strlcat(msg, steps, sizeof(msg));
	if (game->collectables == 0)
		mlx_string_put(game->mlxptr, game->winptr, 10,
			40, 0xFFFF00, info);
	mlx_string_put(game->mlxptr, game->winptr, 10,
		20, 0xFFFFFF, "                                ");
	mlx_string_put(game->mlxptr, game->winptr, 10,
		20, 0xFFFFFF, msg);
	free(steps);
}
