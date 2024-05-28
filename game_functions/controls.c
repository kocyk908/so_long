/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:00:43 by lkoc              #+#    #+#             */
/*   Updated: 2024/05/13 12:00:55 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	keyboard_w(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->player_x;
	j = game->player_y;
	if (movement == 119)
	{
		game->last_move = 119;
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = proper_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	ft_printf("Steps taken: %i\n", game->steps);
	return (1);
}

static int	keyboard_s(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->player_x;
	j = game->player_y;
	if (movement == 115)
	{
		game->last_move = 115;
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = proper_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	ft_printf("Steps taken: %i\n", game->steps);
	return (1);
}

static int	keyboard_a(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->player_x;
	j = game->player_y;
	if (movement == 97)
	{
		game->last_move = 97;
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = proper_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	ft_printf("Steps taken: %i\n", game->steps);
	return (1);
}

static int	keyboard_d(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->player_x;
	j = game->player_y;
	if (movement == 100)
	{
		game->last_move = 100;
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = proper_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	ft_printf("Steps taken: %i\n", game->steps);
	return (1);
}

int	controls_working(int command, t_complete *game)
{
	int	works;

	if (command == XK_Escape)
		exit_point(game);
	if (command == 119)
		works = keyboard_w(game, command);
	if (command == 115)
		works = keyboard_s(game, command);
	if (command == 97)
		works = keyboard_a(game, command);
	if (command == 100)
		works = keyboard_d(game, command);
	if (works)
		adding_in_graphics(game);
	return (1);
}
