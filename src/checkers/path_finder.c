#include "../utils/headers/so_long.h"

int	check_map_rectangular(t_game *game)
{
	int i;
	int map_width;
	int line_len;

	i = 1;
	if (game->map == NULL || game->map_height == 0)
		return (0);
	map_width = ft_strlen(game->map[0]) - 1;
	while (i < game->map_height)
	{
		line_len = ft_strlen(game->map[i]) - 1;
		if (i == game->map_height - 1)
			line_len = line_len + 1;
		if (line_len != map_width)
			return (0);
		i++;
	}
	game->map_width = map_width;
	return (1);
}

int check_map_border(t_game *game)
{
    int i;
    
    // for (i = 0; i < game->map_width; i++)
    // {
    //     if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
    //         return (0);
    // }
    // for (i = 0; i < game->map_height; i++)
    // {
    //     if (game->map[i][0] != '1' || game->map[i][game->map_width] != '1')
    //         return (0);
    // }
    return (1);
}

void flood_fill(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;

    map[y][x] = 'V';
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}

int check_path_to_exit(t_game *game)
{
    // char **map_copy = malloc(sizeof(char *) * (game->map_height + 1));
    // for (int i = 0; i < game->map_height; i++)
    //     map_copy[i] = ft_strdup(game->map[i]);
    // flood_fill(map_copy, game->player_x, game->player_y);
    // for (int y = 0; y < game->map_height; y++)
    // {
    //     for (int x = 0; x < game->map_width; x++)
    //     {
    //         if (game->map[y][x] == 'E' && map_copy[y][x] != 'V')
    //         {
    //             for (int i = 0; i < game->map_height; i++)
    //                 free(map_copy[i]);
    //             free(map_copy);
    //             return (0);
    //         }
    //     }
    // }
    // for (int i = 0; i < game->map_height; i++)
    //     free(map_copy[i]);
    // free(map_copy);
    return (1);
}

int validate_map(t_game *game)
{
    if (!check_map_rectangular(game))
    {
        printf("Error: Map is not rectangular\n");
        return (0);
    }
    if (!check_map_border(game))
    {
        printf("Error: Map is not surrounded by walls\n");
        return (0);
    }
    if (!check_path_to_exit(game))
    {
        printf("Error: No valid path from player to exit\n");
        return (0);
    }
    return (1);
}
