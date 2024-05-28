/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpath_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:03:24 by lkoc              #+#    #+#             */
/*   Updated: 2024/05/28 15:03:25 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:13:18 by lkoc              #+#    #+#             */
/*   Updated: 2024/05/16 14:13:20 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_within_bounds(int x, int y, t_complete *game)
{
	return (x >= 0 && x < game->widthmap && y >= 0 && y < game->heightmap);
}

static bool	**initialize_visited(int height, int width)
{
	bool	**visited;
	int		i;

	i = 0;
	visited = malloc(height * sizeof(bool *));
	while (i < height)
	{
		visited[i] = malloc(width * sizeof(bool));
		memset(visited[i], false, width * sizeof(bool));
		i++;
	}
	return (visited);
}

static void	free_visited(bool **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static void	dfs_collect(t_position current, bool **visited,
			int directions[4][2], t_complete *game)
{
	int			k;
	t_position	next;

	k = 0;
	if (!is_within_bounds(current.x, current.y, game))
		return ;
	if (visited[current.y][current.x])
		return ;
	if (game->map[current.y][current.x] == 'C')
		game->collect_count++;
	visited[current.y][current.x] = true;
	while (k < 4)
	{
		next.x = current.x + directions[k][0];
		next.y = current.y + directions[k][1];
		if (valid_move_coll(game->map, visited, next.x, next.y))
		{
			dfs_collect(next, visited, directions, game);
		}
		k++;
	}
}

int	can_collect_all(t_complete *game)
{
	bool		**visited;
	int			directions[4][2];
	t_position	start;

	visited = initialize_visited(game->heightmap, game->widthmap);
	initialize_directions(directions);
	start.x = game->player_x;
	start.y = game->player_y;
	game->collect_count = 0;
	dfs_collect(start, visited, directions, game);
	free_visited(visited, game->heightmap);
	if (game->collect_count == game->coincount)
	{
		return (1);
	}
	else
		return (0);
}
