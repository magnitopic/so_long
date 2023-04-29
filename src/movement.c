/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:56:24 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/29 16:34:32 by alaparic         ###   ########.fr       */
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
