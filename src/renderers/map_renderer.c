#include "../utils/headers/so_long.h"

void load_player(t_game *game, int width, int height)
{
    int		i;
	char *file_paths[] = {
        "./src/utils/textures/tilesets/Cute_Fantasy_Free/Player/Sprites/Player_Resized_1.xpm",
        "./src/utils/textures/tilesets/Cute_Fantasy_Free/Player/Sprites/Player_Resized_2.xpm",
        "./src/utils/textures/tilesets/Cute_Fantasy_Free/Player/Sprites/Player_Resized_3.xpm",
        "./src/utils/textures/tilesets/Cute_Fantasy_Free/Player/Sprites/Player_Resized_4.xpm",
        "./src/utils/textures/tilesets/Cute_Fantasy_Free/Player/Sprites/Player_Resized_5.xpm",
        "./src/utils/textures/tilesets/Cute_Fantasy_Free/Player/Sprites/Player_Resized_6.xpm"
    };
	i = 0;
	while (i < 6)
	{
		game->img_player[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, file_paths[i], &width, &height);
        if (!game->img_player[i].img_ptr)
        {
            printf("Failed to load image: %s\n", file_paths[i]);
            return;
        }
        game->img_player[i].width = width;
        game->img_player[i].height = height;
		i++;
	}
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	width = 48;
	height = 48;
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "./src/utils/textures/tilesets/Cute_Fantasy_Free/Tiles/FarmLand_Tile.xpm", &width, &height);
	game->img_empty = mlx_xpm_file_to_image(game->mlx_ptr, "./src/utils/textures/tilesets/Cute_Fantasy_Free/Tiles/Grass_Middle_Resized.xpm", &width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx_ptr, "./src/utils/textures/tilesets/Cute_Fantasy_Free/Decoration/Chest_Resized.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "./src/utils/textures/tilesets/mystic_woods_free_2.2/sprites/tilesets/walls/wooden_door_b.xpm", &width, &height);
	load_player(game, width, height);
}

void	render_tile(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_empty, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_player->img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

    mlx_clear_window(game->mlx_ptr, game->window);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
			render_tile(game, x++, y);
		y++;
	}
}
