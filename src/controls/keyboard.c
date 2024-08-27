#include "../utils/headers/so_long.h"

void	handle_keypress(int keycode, t_game *game)
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
