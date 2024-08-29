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
        game->img_player[i].width = width;
        game->img_player[i].height = height;
		i++;
	}
}

void	load_enemy(t_game *game, int width, int height)
{
	int		i;
	char *file_paths[] = {
		"./src/utils/textures/tilesets/Cute_Fantasy_Free/Enemies/Images/Skeleton_1.xpm",
		"./src/utils/textures/tilesets/Cute_Fantasy_Free/Enemies/Images/Skeleton_2.xpm",
		"./src/utils/textures/tilesets/Cute_Fantasy_Free/Enemies/Images/Skeleton_3.xpm",
		"./src/utils/textures/tilesets/Cute_Fantasy_Free/Enemies/Images/Skeleton_4.xpm",
		"./src/utils/textures/tilesets/Cute_Fantasy_Free/Enemies/Images/Skeleton_5.xpm",
		"./src/utils/textures/tilesets/Cute_Fantasy_Free/Enemies/Images/Skeleton_6.xpm"
	};
	i = 0;
	while (i < 6)
	{
		game->img_enemy[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, file_paths[i], &width, &height);
        game->img_enemy[i].width = width;
        game->img_enemy[i].height = height;
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
	load_enemy(game, width, height);
}
