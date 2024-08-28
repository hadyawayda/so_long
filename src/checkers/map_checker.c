#include "../utils/headers/so_long.h"

// Function to count the number of lines in the map
int	count_map_lines(char *file)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void print_map_line(char *line)
{
	printf("Line: %s\n", line);
}

int	check_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0); // Failed to open file

	// Get the number of lines in the map
	game->map_height = count_map_lines(file);
	if (game->map_height == 0)
		return (0); // Empty or invalid file

	// Allocate memory for the map
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0); // Allocation failed

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		// Remove the newline character from the end of the line, if present
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';

		game->map[i] = line;

		// Set map width for the first line
		if (i == 0)
			game->map_width = ft_strlen(line);

		// Ensure all lines have the same width
		if ((int)ft_strlen(line) != game->map_width)
		{
			free(line);
			return (0); // Not a rectangular map
		}
		print_map_line(line);
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL; // Null-terminate the map array
	close(fd);

	return (1);
}
