/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:16:02 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/23 13:01:41 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	close_window(int key, t_game *game)
{
	(void)key;
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

static int	event_handler(int key, t_game *game)
{
	if (key == 53)
		close_window(key, game);
	else if (key == 13 || key == 126)
		ft_printf("up\n");
	else if (key == 0 || key == 123)
		ft_printf("left\n");
	else if (key == 1 || key == 125)
		ft_printf("down\n");
	else if (key == 2 || key == 124)
		ft_printf("right\n");
	return (0);
}

static void	put_sprites(t_game *game)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->mlx, "./textures/salida.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, 64*2, 64*2);
	img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, 64, 0);
	mlx_put_image_to_window(game->mlx, game->win, img, 64, 64*2);
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 64);
	img = mlx_xpm_file_to_image(game->mlx, "./textures/coin.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, 64*0, 64*0);
	img = mlx_xpm_file_to_image(game->mlx, "./textures/space.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, 64*1, 64*1);
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 64*2);
	img = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 64*2);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		raise_error("Expected one parameter");
		return (1);
	}
	game = malloc(sizeof(t_game));
	read_map(argv, game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 64 * 15, 64 * 15, "so_long");
	// img drawing
	put_sprites(game);
	// Events
	mlx_hook(game->win, 2, 1L << 0, event_handler, game);
	mlx_hook(game->win, 17, 0L, close_window, game);
	mlx_loop(game->mlx);
}
