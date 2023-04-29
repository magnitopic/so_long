/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:41:59 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/29 18:19:48 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	flood(char **map, int x, int y)
{
	map[y][x] = 'F';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'F')
		flood(map, x, y + 1);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'F')
		flood(map, x, y - 1);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'F')
		flood(map, x + 1, y);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'F')
		flood(map, x - 1, y);
}

static void	check_chars(t_game *game)
{
	int		i;
	int		j;
	char	pos;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			pos = game->map[i][j];
			if (pos != '1' && pos != '0' && pos != 'E' && pos != 'P'
				&& pos != 'C')
				raise_error("Map file contains invalid values.");
			if (((i == 0 || i == game->len_y - 1) && pos != '1')
				|| ((j == 0 || j == game->len_x - 1) && pos != '1'))
				raise_error("Map must be surrounded by walls.");
			j++;
		}
		i++;
	}
}

void	validate_map(t_game *game)
{
	game->coins = count_items(game->map, 'C');
	if (count_items(game->map, 'P') != 1)
		raise_error("Map must have one player starting position.");
	if (count_items(game->map, 'E') != 1)
		raise_error("Map must have one exit.");
	if (game->coins < 1)
		raise_error("Map must have at least one coin.");
	check_chars(game);
	find_item(game, &game->p_x, &game->p_y, 'P');
	find_item(game, &game->e_x, &game->e_y, 'E');
	flood(game->flood_map, game->p_x, game->p_y);
	if (count_items(game->flood_map, 'P') + count_items(game->flood_map, 'C') \
	+ count_items(game->flood_map, 'E') != 0)
		raise_error("Some map elements are inaccesible.");
}
