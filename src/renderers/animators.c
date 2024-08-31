/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:35:21 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/31 00:56:59 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/so_long.h"

int	animate_enemy(t_game *game)
{
	static int	last_time = 0;
	int			current_time;

	current_time = clock();
	if ((current_time - last_time) > CLOCKS_PER_SEC / 5)
	{
		last_time = current_time;
		move_enemy(game);
	}
	return (0);
}

int	animate_map(t_game *game)
{
	static int	last_time = 0;
	int			current_time;

	current_time = clock();
	if ((current_time - last_time) > CLOCKS_PER_SEC / 10)
		render_map(game);
	return (0);
}

int	update(t_game *game)
{
	render_map(game);
	animate_enemy(game);
	display_move_count(game);
	return (0);
}

int	close_game(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}
