#include "../utils/headers/so_long.h"

void	load_player(t_game *game, int width, int height)
{
	int	offset_x = (TILE_SIZE - width) / 2;
	int	offset_y = (TILE_SIZE - height) / 2;

	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "./src/utils/textures/tilesets/Cute_Fantasy_Free/Player/Player.xpm", &width, &height);
}

void	load_exit(t_game *game, int width, int height)
{
	int	offset_x = (TILE_SIZE - width) / 2;
	int	offset_y = (TILE_SIZE - height) / 2;

	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "./src/utils/textures/tilesets/mystic_woods_free_2.2/sprites/tilesets/walls/wooden_door_b.xpm", &width, &height);
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
	load_player(game, width, height);
	load_exit(game, width, height);
}

void	render_tile(t_game *game, int x, int y)
{
	printf("Tile: %c\n", game->map[y][x]);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_empty, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	printf("map height: %d\n", game->map_height);
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
