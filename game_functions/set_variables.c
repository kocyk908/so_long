/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:54:37 by lkoc              #+#    #+#             */
/*   Updated: 2024/05/14 13:54:38 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_variables(int *x, int *y, int height, int width)
{
	*x = width * 40;
	*y = height * 40;
}

void	set_zeros(int *x, int *y, int *z)
{
	*x = 0;
	*y = 0;
	*z = 0;
}

void	initialize_directions(int directions[4][2])
{
	directions[0][0] = -1;
	directions[0][1] = 0;
	directions[1][0] = 1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = -1;
	directions[3][0] = 0;
	directions[3][1] = 1;
}

bool	valid_move(char **map, bool **visited, int x, int y)
{
	return ((map[y][x] == '0' || map[y][x] == 'C'
			|| map[y][x] == 'E') && !visited[y][x]);
}

bool	valid_move_coll(char **map, bool **visited, int x, int y)
{
	return ((map[y][x] == '0' || map[y][x] == 'C') && !visited[y][x]);
}
