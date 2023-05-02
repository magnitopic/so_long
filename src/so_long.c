/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:16:02 by alaparic          #+#    #+#             */
/*   Updated: 2023/05/02 17:16:42 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
			if (game->map[j][i] == '1')
				put_image(game, i, j, "wall.xpm");
			else
				put_image(game, i, j, "space.xpm");
			if (game->map[j][i] == 'C')
				put_image(game, i, j, "coin.xpm");
			else if (game->map[j][i] == 'P')
				put_image(game, i, j, "player.xpm");
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	*game_name;

	if (argc != 2)
		raise_error("Expected one parameter");
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		exit(1);
	read_map(argv, game);
	game->mlx = mlx_init();
	game_name = ft_strjoin("so_long - ", argv[1]);
	game->win = mlx_new_window \
	(game->mlx, 64 * game->len_x, 64 * game->len_y, game_name);
	free(game_name);
	put_sprites(game);
	mlx_hook(game->win, 2, 1L << 0, event_handler, game);
	mlx_hook(game->win, 17, 0L, close_window, game);
	mlx_loop(game->mlx);
}
