#include "utils/headers/so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->window);
	free(game->map);
	free(game);
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

int on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->window);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_game *game)
{
	(void)game;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}
void print_map(t_game *game)
{
    for (int y = 0; y < game->map_height; y++)
    {
        printf("Row %d: %s\n", y, game->map[y]);
    }
}
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}
	if (check_map(argv[1], &game))
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		return (1);
	}
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);
	game.window = mlx_new_window(game.mlx_ptr, game.map_width * TILE_SIZE, game.map_height * TILE_SIZE, "so_long");
	if (!game.window)
		return (1);
	// print_map(&game);
	// load_textures(&game);
	// render_map(&game);
	// initialize_player_position(&game);
	// mlx_key_hook(game.window, handle_keypress, &game);
	// mlx_hook(game.window, KeyRelease, KeyReleaseMask, &close_window, &game);
	mlx_hook(game.window, KeyRelease, KeyReleaseMask, &on_keypress, &game);
	mlx_hook(game.window, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
	mlx_loop(game.mlx_ptr);
	// cleanup_game(&game);
	return (0);
}
