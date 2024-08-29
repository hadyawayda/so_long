#include "../utils/headers/so_long.h"

void init_enemy(t_game *game, int start_x, int start_y)
{
    game->enemy.x = start_x;
    game->enemy.y = start_y;
    game->enemy.direction = 1;
}

void move_enemy(t_game *game)
{
    int new_x = game->enemy.x + game->enemy.direction;

	init_enemy(game, game->player_x + 2, game->player_y + 2);
    // if (new_x < 0 || new_x >= game->map_width || game->map[game->enemy.y][new_x] == '1')
    //     game->enemy.direction *= -1;
    // else
    //     game->enemy.x = new_x;
    if (game->enemy.x == game->player_x && game->enemy.y == game->player_y)
    {
        printf("You lost!\n");
        close_game(game);
    }
}
