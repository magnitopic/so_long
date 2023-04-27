/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:56:24 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/27 18:16:01 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[game->p_y + new_y][game->p_x + new_x] != '1')
	{
		put_image(game, game->p_x, game->p_y, "space.xpm");
		put_image(game, (game->p_x + new_x), (game->p_y + new_y), "player.xpm");
		game->p_x = game->p_x + new_x;
		game->p_y = game->p_y + new_y;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}

int	event_handler(int key, t_game *game)
{
	if (key == 53)
		close_window(game);
	else if (key == 13 || key == 126)
		move_player(game, 0, -1);
	else if (key == 0 || key == 123)
		move_player(game, -1, 0);
	else if (key == 1 || key == 125)
		move_player(game, 0, 1);
	else if (key == 2 || key == 124)
		move_player(game, 1, 0);
	return (0);
}
