/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:35:11 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/29 21:39:35 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/so_long.h"

void	move_left(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x - 1;
	new_y = game->player_y;
	move_player(game, new_x, new_y);
}

void	move_right(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + 1;
	new_y = game->player_y;
	move_player(game, new_x, new_y);
}

void	move_up(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y - 1;
	move_player(game, new_x, new_y);
}

void	move_down(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y + 1;
	move_player(game, new_x, new_y);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	if (keycode == 65361 || keycode == 'a')
		move_left(game);
	if (keycode == 65363 || keycode == 'd')
		move_right(game);
	if (keycode == 65362 || keycode == 'w')
		move_up(game);
	if (keycode == 65364 || keycode == 's')
		move_down(game);
	return (0);
}
