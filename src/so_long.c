/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:16:02 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/18 19:09:24 by alaparic         ###   ########.fr       */
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

// ! get-next-lie already used here and need a different system
int	map_len(int fd)
{
	char	*line;
	int		len;

	len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		len++;
	}
	free(line);
	return (len);
}

void	read_map(char *argv, t_game *game)
{
	int		i;
	int		fd;
	char	**map;

	fd = open(argv, O_RDONLY);
	map = malloc((map_len(fd) + 1));
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i] != NULL)
	{
		map[i] = get_next_line(fd);
		i++;
		ft_printf("I: %d", i);
	}
	map[i] = NULL;
	ft_printf("%s", *map);
	game->map = map;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	game = malloc(sizeof(t_game));
	read_map(argv[1], game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 64 * 15, 64 * 15, "so_long");
	// img drawing
	put_sprites(game);
	// Events
	mlx_hook(game->win, 2, 1L << 0, event_handler, game);
	mlx_hook(game->win, 17, 0L, close_window, game);

	mlx_loop(game->mlx);
}
