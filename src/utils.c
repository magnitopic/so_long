/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:53:33 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/26 19:00:29 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	raise_error(char *message)
{
	ft_printf("\033[0;31mError\n%s\n\033[0m", message);
	exit (1);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_matrix(game->map);
	exit(0);
}

void	find_item(t_game *game, int *x, int *y, char item)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->len_x)
	{
		j = 0;
		while (j < game->len_y)
		{
			if (game->map[j][i] == item)
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
	*x = -1;
	*y = -1;
}
