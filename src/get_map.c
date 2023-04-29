/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:48:14 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/29 15:02:15 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_extension(char **argv)
{
	char	*file_ext;

	file_ext = ft_strrchr(argv[1], '.');
	if (!file_ext || ft_strncmp(file_ext + 1, "ber", ft_strlen(argv[1])) != 0)
		raise_error("Map with invalid extension.");
}

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

static void	validate_map(t_game *game)
{
	int	x;
	int	y;

	game->coins = count_items(game->map, 'P');
	find_item(game, &x, &y, 'P');
	if (x == -1 || y == -1)
		raise_error("Map must have a player starting position.");
	find_item(game, &x, &y, 'C');
	if (x == -1 || y == -1)
		raise_error("Map must have at least one coin.");
	find_item(game, &x, &y, 'E');
	if (x == -1 || y == -1)
		raise_error("Map must have an exit.");
	find_item(game, &game->p_x, &game->p_y, 'P');
	flood(game->flood_map, game->p_x, game->p_y);
	if (count_items(game->flood_map, 'P') + count_items(game->flood_map, 'C') \
	+ count_items(game->flood_map, 'E') != 0)
		raise_error("Some map elements are inaccesible.");
	//check_walls();
}

void	read_map(char **argv, t_game *game)
{
	char	*file;
	char	*line;
	int		fd;

	check_extension(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		raise_error("Error when opening file. Does the file exist?");
	file = ft_calloc(1, 1);
	game->len_y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		file = ft_fstrjoin(file, line);
		free(line);
		line = get_next_line(fd);
		game->len_y++;
	}
	close(fd);
	game->map = ft_split(file, '\n');
	game->flood_map = ft_split(file, '\n');
	game->len_x = ft_strlen(*(game->map));
	validate_map(game);
	free(line);
	free(file);
}
