/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:48:14 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/24 16:59:51 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_extension(char **argv)
{
	char	*file_ext;

	file_ext = ft_strrchr(argv[1], '.');
	if (!file_ext || ft_strncmp(file_ext + 1, "ber", ft_strlen(argv[1])) != 0)
		raise_error("Map with invalid extension");
}

void	read_map(char **argv, t_game *game)
{
	char	*file;
	char	*line;
	int		fd;

	check_extension(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		raise_error("Error when opening file. Does the file exist?");
	file = "";
	game->len_y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_strlcat(file, line, ft_strlen(file));
		free(line);
		line = get_next_line(fd);
		game->len_y++;
	}
	free(line);
	close(fd);
	game->map = ft_split(file, '\n');
	game->len_x = ft_strlen(*(game->map));
}
