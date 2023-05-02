/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:48:14 by alaparic          #+#    #+#             */
/*   Updated: 2023/05/02 12:04:58 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_extension(char **argv)
{
	char	*file_ext;

	file_ext = ft_strrchr(argv[1], '.');
	if (!file_ext || ft_strncmp(file_ext + 1, "ber", ft_strlen(argv[1])) != 0)
		raise_error("Map with invalid extension.");
}

static char	*get_lines(t_game *game, int fd)
{
	char	*file;
	char	*line;

	line = get_next_line(fd);
	file = ft_calloc(1, 1);
	if (!file)
		exit(1);
	game->len_y = 0;
	game->len_x = ft_strlen(line);
	while (line != NULL)
	{
		file = ft_fstrjoin(file, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (file);
}

void	read_map(char **argv, t_game *game)
{
	char	*file;
	int		fd;
	int		i;

	check_extension(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		raise_error("Error when opening file. Does the file exist?");
	file = get_lines(game, fd);
	close(fd);
	game->map = ft_split(file, '\n');
	game->flood_map = ft_split(file, '\n');
	game->len_x = ft_strlen(*(game->map));
	i = 0;
	while (game->map[i++] != NULL)
		game->len_y++;
	validate_map(game);
	free(file);
}
