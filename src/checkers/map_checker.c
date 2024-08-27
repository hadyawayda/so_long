#include "../utils/headers/so_long.h"

bool	check_map(char *argv)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (line[j])
		{
			if (line[j] != '1' && line[j] != '0' && line[j] != '\n')
				return (false);
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	if (i == 0)
		return (false);
	return (true);
}