#include "../utils/headers/so_long.h"

int	count_map_lines(int fd)
{
	char	*line;
	int		lines;

	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1 || (ft_strlen(line) == 1 && line[0] != '\n'))
			lines++;
		free(line);
		line = get_next_line(fd);
	}
	lseek(fd, 0, SEEK_SET);
	return (lines);
}

void	parse_map_columns(int fd, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	while ((line = get_next_line(fd)))
	{
		if (!line)
			break;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		game->map[i] = line;
		i++;
	}
	game->map[i] = NULL;
}

int	parse_map_lines(char *file, t_game *game)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	game->map_height = count_map_lines(fd);
	if (game->map_height == 0)
		return (0);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0);
	parse_map_columns(fd, game);
	close(fd);
	return (1);
}

