#include "../utils/headers/so_long.h"

void	initialize_assets(t_game *game)
{
    int x, y;

    game->collectibles = 0;
    game->collected = 0;
    for (y = 0; y < game->map_height; y++)
    {
        for (x = 0; x < game->map_width; x++)
        {
            if (game->map[y][x] == 'C')
                game->collectibles++;
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
        }
    }
}

// remove key press/release events if memory leaks persist
void	load_game(t_game *game)
{
	game->enemy.x = 5;
	game->enemy.y = 4;
	game->enemy.direction = 1;

	load_textures(game);
	render_map(game);
	initialize_assets(game);
	mlx_loop_hook(game->mlx_ptr, &update, game);
	mlx_hook(game->window, 2, 1L << 0, &key_press, game);
    mlx_hook(game->window, 3, 1L << 1, &key_release, game);
	mlx_key_hook(game->window, handle_keypress, game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &close_game, game);
	mlx_loop(game->mlx_ptr);
}

void	cleanup_game(t_game *game)
{
	// free_images(game);
}

int	close_game(t_game *game)
{
	cleanup_game(game);
	mlx_destroy_window(game->mlx_ptr, game->window);
	mlx_destroy_display(game->mlx_ptr);
	exit(0);
	return (0);
}
