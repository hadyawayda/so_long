#include "../utils/headers/so_long.h"

void	move_left(t_game *game)
{
	int	new_x = game->player_x - 1;
	int	y = game->player_y;

	if (game->map[y][new_x] != '1')  // Check if the new position is not a wall
	{
		game->map[y][game->player_x] = '0';  // Clear the old position
		game->player_x = new_x;
		game->map[y][new_x] = 'P';  // Update the map with the new position
		// render_map(game);  // Redraw the map with the new player position
	}
}

void	move_right(t_game *game)
{
	int	new_x = game->player_x + 1;
	int	y = game->player_y;

	if (game->map[y][new_x] != '1')
	{
		game->map[y][game->player_x] = '0';
		game->player_x = new_x;
		game->map[y][new_x] = 'P';
		// render_map(game);
	}
}

void	move_up(t_game *game)
{
	int	new_y = game->player_y - 1;
	int	x = game->player_x;

	if (game->map[new_y][x] != '1')
	{
		game->map[game->player_y][x] = '0';
		game->player_y = new_y;
		game->map[new_y][x] = 'P';
		// render_map(game);
	}
}

void	move_down(t_game *game)
{
	int	new_y = game->player_y + 1;
	int	x = game->player_x;

	if (game->map[new_y][x] != '1')
	{
		game->map[game->player_y][x] = '0';
		game->player_y = new_y;
		game->map[new_y][x] = 'P';
		// render_map(game);
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	if (keycode == 65361)
		move_left(game);
	if (keycode == 65363)
		move_right(game);
	if (keycode == 65362)
		move_up(game);
	if (keycode == 65364)
		move_down(game);
}
