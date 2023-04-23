/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:16:02 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/23 17:20:25 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	sprites(t_game *game, int i, int j)
{
	void	*img;
	int		img_width;
	int		img_height;

	if (game->map[j][i] == '1')
		img = mlx_xpm_file_to_image \
		(game->mlx, "./textures/wall.xpm", &img_width, &img_height);
	else
		img = mlx_xpm_file_to_image \
		(game->mlx, "./textures/space.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, i * 64, j * 64);
	if (game->map[j][i] == 'C')
		img = mlx_xpm_file_to_image \
		(game->mlx, "./textures/coin.xpm", &img_width, &img_height);
	else if (game->map[j][i] == 'E')
		img = mlx_xpm_file_to_image \
		(game->mlx, "./textures/salida.xpm", &img_width, &img_height);
	else if (game->map[j][i] == 'P')
		img = mlx_xpm_file_to_image \
		(game->mlx, "./textures/player.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, i * 64, j * 64);
}

static void	put_sprites(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->len_x)
	{
		j = 0;
		while (j < game->len_y)
		{
			sprites(game, i, j);
			j++;
		}
		i++;
	}
}

t_game	*start_game_data(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->p_x = 0;
	game->p_y = 0;
	game->moves = 0;
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		raise_error("Expected one parameter");
	game = start_game_data();
	read_map(argv, game);
	game->mlx = mlx_init();
	game->win = mlx_new_window \
	(game->mlx, 64 * game->len_x, 64 * game->len_y, "so_long");
	find_item(game, &game->p_x, &game->p_y, 'P');
	put_sprites(game);
	mlx_hook(game->win, 2, 1L << 0, event_handler, game);
	mlx_hook(game->win, 17, 0L, close_window, game);
	mlx_loop(game->mlx);
}

rearrangement