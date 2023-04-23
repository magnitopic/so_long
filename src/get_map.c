/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:48:14 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/23 13:27:29 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	raise_error(char *message)
{
	ft_printf("\033[0;31mError\n%s\n\033[0m", message);
	exit (1);
}

void	read_map(char **argv, t_game *game)
{
	char	*file;
	char	*line;
	int		fd;

	(void)game;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		raise_error("Error when opening file. Does the file exist?");
	file = "";
	game->len_y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		file = ft_strjoin(file, line);
		free(line);
		line = get_next_line(fd);
		game->len_y++;
	}
	free(line);
	game->map = ft_split(file, '\n');
	game->len_x = ft_strlen(*(game->map));
}