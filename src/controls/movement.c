#include "../utils/headers/so_long.h"

int key_press(int keycode, t_game *game)
{
    game->keys[keycode] = 1;
    return (0);
}

int key_release(int keycode, t_game *game)
{
    game->keys[keycode] = 0;
    return (0);
}

void display_move_count(t_game *game)
{
    char *move_count_str;
    char *text;

    move_count_str = ft_itoa(game->moves);
    text = ft_strjoin("Total Moves: ", move_count_str);
    mlx_string_put(game->mlx_ptr, game->window, 10, 10, 0xFFFFFF, text);
    free(move_count_str);
    free(text);
}

void	move_player(t_game *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] == '1')
        return;
    if (game->map[new_y][new_x] == 'C')
    {
        game->collected++;
        game->map[new_y][new_x] = '0';
		printf("Total collected items: %d/%d\n", game->collected, game->collectibles);
    }
    if (game->map[new_y][new_x] == 'E')
    {
        if (game->collected != game->collectibles)
        {
            printf("You must collect all items before exiting!\n");
            return;
        }
        else
            close_game(game);
    }
    game->map[game->player_y][game->player_x] = '0';
    game->player_x = new_x;
    game->player_y = new_y;
    game->map[new_y][new_x] = 'P';
    game->moves++;
    render_map(game);
	display_move_count(game);
}
