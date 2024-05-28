/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:01:58 by lkoc              #+#    #+#             */
/*   Updated: 2024/05/13 12:01:58 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	character_valid(t_complete *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->heightmap - 1)
	{
		w = 0;
		while (w <= game->widthmap)
		{
			count_checker(game, h, w);
			w++;
		}
		h++;
	}
	if (!(game->playercount == 1 && game->coincount >= 1
			&& game->exitcount == 1))
	{
		ft_printf("\nError\nSomething is wrong!\n");
		ft_printf("'C', 'E' or 'P' issue\n");
		exit_point(game);
	}
}

void	check_errors(t_complete *game)
{
	if_walls(game);
	character_valid(game);
}
