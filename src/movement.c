/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:56:24 by alaparic          #+#    #+#             */
/*   Updated: 2023/06/16 18:04:50 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[game->p_y + new_y][game->p_x + new_x] != '1')
	{
		ft_printf("\033[0;36mMoves: %d\n\033[0m", ++(game->moves));
		put_image(game, game->p_x, game->p_y, "space.xpm");
		put_image(game, game->p_x + new_x, game->p_y + new_y, "space.xpm");
		put_image(game, game->p_x + new_x, game->p_y + new_y, "player.xpm");
		if (game->map[game->p_y + new_y][game->p_x + new_x] == 'C')
		{
			game->coins--;
			if (game->coins == 0)
				put_image(game, game->e_x, game->e_y, "exit.xpm");
		}
		game->p_x = game->p_x + new_x;
		game->p_y = game->p_y + new_y;
		if (game->map[game->p_y][game->p_x] != 'E')
			game->map[game->p_y][game->p_x] = '0';
		else if (game->coins == 0)
		{
			ft_printf("\033[0;32mThe player has reached the exit. So long!\n");
			exit(0);
		}
	}
}

int	event_handler(enum e_keys key, t_game *game)
{
	if (key == ESC)
		close_window(game);
	else if (key == W || key == UP)
		move_player(game, 0, -1);
	else if (key == A || key == LEFT)
		move_player(game, -1, 0);
	else if (key == S || key == DOWN)
		move_player(game, 0, 1);
	else if (key == D || key == RIGHT)
		move_player(game, 1, 0);
	return (0);
}
