#include "../utils/headers/so_long.h"

int move_enemy(t_game *game)
{
    printf("Enemy position: (%d, %d)\n", game->enemy.x, game->enemy.y);
    int new_x = game->enemy.x + game->enemy.direction;

    if (new_x > 12 || new_x < 5)
    {
        game->enemy.direction *= -1;
        new_x = game->enemy.x + game->enemy.direction;
    }
    if (new_x >= 0 && new_x < game->map_width && game->map[game->enemy.y][new_x] != '1')
        game->enemy.x = new_x;
    if (game->enemy.x == game->player_x && game->enemy.y == game->player_y)
    {
        printf("You lost!\n");
        close_game(game);
    }
    return (0);
}
