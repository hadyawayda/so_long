#include "../utils/headers/so_long.h"

void	load_game(t_game *game)
{
	load_textures(game);
	render_map(game);
	display_move_count(game);
	init_collectibles(game);
	initialize_player_position(game);
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
