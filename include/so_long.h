/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:16:33 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/23 15:54:40 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		len_x;
	int		len_y;
	int		p_x;
	int		p_y;
}	t_game;

void	read_map(char **argv, t_game *game);
void	raise_error(char *message);
int		find_item(t_game *game, int *x, int *y, char item);

#endif
