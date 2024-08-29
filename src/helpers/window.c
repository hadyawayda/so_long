#include "../utils/headers/so_long.h"

int animate_player(t_game *game)
{
    static int frame = 0;
    static int last_time = 0;
    int current_time;

    current_time = clock();
    if ((current_time - last_time) > CLOCKS_PER_SEC / 24)
    {
        frame = (frame + 1) % 6;
        last_time = current_time;
        mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_player[frame].img_ptr, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
    }
    return (0);
}

// remove key press/release events if memory leaks persist
void	load_game(t_game *game)
{
	load_textures(game);
	render_map(game);
	mlx_loop_hook(game->mlx_ptr, &animate_player, game);
	display_move_count(game);
	init_collectibles(game);
	initialize_player_position(game);
	mlx_hook(game->window, 2, 1L << 0, &key_press, game);
    mlx_hook(game->window, 3, 1L << 1, &key_release, game);
	mlx_key_hook(game->window, handle_keypress, game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &close_game, game);
	mlx_loop(game->mlx_ptr);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->window);
	mlx_destroy_display(game->mlx_ptr);
	exit(0);
	return (0);
}

void	initialize_player_position(t_game *game)
{
	for (int y = 0; y < game->map_height; y++)
	{
		for (int x = 0; x < game->map_width; x++)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				break;
			}
		}
	}
}

void	init_collectibles(t_game *game)
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
        }
    }
}
