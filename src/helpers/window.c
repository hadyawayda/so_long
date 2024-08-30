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

void spawn_enemy(t_game *game)
{
    srand(time(NULL));
    int x, y;
    
    do {
        x = rand() % game->map_width;
        y = rand() % game->map_height;
    } while (game->map[y][x] == '1' || game->map[y][x] == 'P'); // Ensure not spawning on walls or player

    game->enemy.x = x;
    game->enemy.y = y;
}

void	load_game(t_game *game)
{
	load_textures(game);
	initialize_assets(game);
	spawn_enemy(game);
	mlx_loop_hook(game->mlx_ptr, &update, game);
	mlx_hook(game->window, 2, 1L << 0, &key_press, game);
    mlx_hook(game->window, 3, 1L << 1, &key_release, game);
	mlx_key_hook(game->window, handle_keypress, game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &close_game, game);
	mlx_loop(game->mlx_ptr);
}

void	window_cleaner(t_game *game)
{
    if (game->img_wall)
        mlx_destroy_image(game->mlx_ptr, game->img_wall);
    if (game->img_collectible)
        mlx_destroy_image(game->mlx_ptr, game->img_collectible);
    if (game->img_exit)
        mlx_destroy_image(game->mlx_ptr, game->img_exit);
    if (game->img_empty)
        mlx_destroy_image(game->mlx_ptr, game->img_empty);
    if (game->window)
        mlx_destroy_window(game->mlx_ptr, game->window);
    if (game->mlx_ptr)
        mlx_destroy_display(game->mlx_ptr);
    free(game->mlx_ptr);
}

void	cleanup_game(t_game *game)
{
	int i;

    if (game->map)
    {
        for (i = 0; i < game->map_height; i++)
        {
            if (game->map[i])
                free(game->map[i]);
        }
        free(game->map);
    }
    for (i = 0; i < 6; i++)
    {
        if (game->img_player[i].img_ptr)
            mlx_destroy_image(game->mlx_ptr, game->img_player[i].img_ptr);
    }
    for (i = 0; i < 6; i++)
    {
        if (game->img_enemy[i].img_ptr)
            mlx_destroy_image(game->mlx_ptr, game->img_enemy[i].img_ptr);
    }
	window_cleaner(game);
}
