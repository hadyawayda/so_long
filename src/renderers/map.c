#include "../utils/headers/so_long.h"

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

void	render_player(t_game *game)
{
	static int frame = 0;
	static int last_time = 0;
	int current_time = clock();

	if ((current_time - last_time) > CLOCKS_PER_SEC / 12)
	{
		frame = (frame + 1) % 6;
		last_time = current_time;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_player[frame].img_ptr, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}

void	render_enemy(t_game *game)
{
	static int frame = 0;
	static int last_time = 0;
	int current_time = clock();

	if ((current_time - last_time) > CLOCKS_PER_SEC / 6)
	{
		frame = (frame + 1) % 6;
		last_time = current_time;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->img_enemy[frame].img_ptr, game->enemy.x * TILE_SIZE, game->enemy.y * TILE_SIZE);
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
		{
			render_tile(game, x, y);
			if (game->map[y][x] == 'P')
				render_player(game);
			if (game->enemy.x == x && game->enemy.y == y)
				render_enemy(game);
			x++;
		}
		y++;
	}
}
