/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:16:33 by alaparic          #+#    #+#             */
/*   Updated: 2023/06/16 18:05:37 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"

/* Enums */
enum e_keys
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	UP = 126,
	LEFT = 123,
	DOWN = 125,
	RIGHT = 124,
	ESC = 53
};

/* Structs */
typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**flood_map;
	int		len_x;
	int		len_y;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		moves;
	int		coins;
}	t_game;

/* Functions */
void	raise_error(char *message);
int		close_window(t_game *game);
void	validate_map(t_game *game);
int		count_items(char **map, char item);
void	read_map(char **argv, t_game *game);
int		event_handler(enum e_keys key, t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
void	find_item(t_game *game, int *x, int *y, char item);
void	put_image(t_game *game, int y, int x, char *sprite);

#endif
