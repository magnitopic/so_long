/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:56:24 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/23 17:15:32 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	void	*img;
	int		img_width;
	int		img_height;

	if (game->map[game->p_y + new_y][game->p_x + new_x] != '1')
	{
		game->map[game->p_y][game->p_x] = '0';
		game->map[game->p_y + new_y][game->p_x + new_x] = 'P';
		img = mlx_xpm_file_to_image \
		(game->mlx, "./textures/space.xpm", &img_width, &img_height);
		mlx_put_image_to_window(game->mlx, game->win, img, \
		game->p_x * 64, game->p_y * 64);
		img = mlx_xpm_file_to_image \
				(game->mlx, "./textures/player.xpm", &img_width, &img_height);
		mlx_put_image_to_window(game->mlx, game->win, img, \
		(game->p_x + new_x) * 64, (game->p_y + new_y) * 64);
		game->p_x = game->p_x + new_x;
		game->p_y = game->p_y + new_y;
	}
}

int	event_handler(int key, t_game *game)
{
	if (key == 53)
	{
		close_window(key, game);
		return (0);
	}
	if (key == 13 || key == 126)
		move_player(game, 0, -1);
	else if (key == 0 || key == 123)
		move_player(game, -1, 0);
	else if (key == 1 || key == 125)
		move_player(game, 0, 1);
	else if (key == 2 || key == 124)
		move_player(game, 1, 0);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	return (0);
}
