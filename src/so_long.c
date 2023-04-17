/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:16:02 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/17 16:09:57 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	close_window(int key, void *game)
{
	(void)key;
	//game = (t_mlx *)game;
	mlx_destroy_window(((t_mlx *)game)->mlx, ((t_mlx *)game)->win);
	exit(0);
	return (0);
}

static int	event_handler(int key, void *game)
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

int	main(void)
{
	t_mlx	*game;
	void	*img;
	int		img_width;
	int		img_height;

	game = malloc(sizeof(t_mlx));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 64 * 20, 64 * 20, "so_long");
	img = mlx_xpm_file_to_image(game->mlx, "./img/salida.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
	img = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, 64, 0);
	mlx_put_image_to_window(game->mlx, game->win, img, 64, 64);
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 64);
	img = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 64*2);
	img = mlx_xpm_file_to_image(game->mlx, "./img/coin.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, 64, 64*2);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_hook(game->win, 2, 1L << 0, event_handler, game);
	mlx_loop(game->mlx);
}
