/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:35:09 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/31 01:05:09 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/so_long.h"

void	move_enemy2(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		game->enemy.x = new_x;
		game->enemy.y = new_y;
	}
	if (game->enemy.x == game->player_x && game->enemy.y == game->player_y)
	{
		ft_printf("You lost!\n");
		close_game(game);
	}
}

int	move_enemy(t_game *game)
{
	int	direction;
	int	new_x;
	int	new_y;

	direction = rand() % 4;
	new_x = game->enemy.x;
	new_y = game->enemy.y;
	if (direction == 0 && new_y > 0 && game->map[new_y - 1][new_x] != '1')
		new_y--;
	else if (direction == 1 && new_y < game->map_height - 1
		&& game->map[new_y + 1][new_x] != '1')
		new_y++;
	else if (direction == 2 && new_x > 0 && game->map[new_y][new_x - 1] != '1')
		new_x--;
	else if (direction == 3 && new_x < game->map_width - 1
		&& game->map[new_y][new_x + 1] != '1')
		new_x++;
	move_enemy2(game, new_x, new_y);
	return (0);
}
