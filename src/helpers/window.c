/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:35:19 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/31 01:19:43 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/so_long.h"

void	spawn_enemy(t_game *game)
{
	int	x;
	int	y;

	srand(time(NULL));
	x = rand() % game->map_width;
	y = rand() % game->map_height;
	while (game->map[y][x] == '1' || game->map[y][x] == 'P')
	{
		x = rand() % game->map_width;
		y = rand() % game->map_height;
	}
	game->enemy.x = x;
	game->enemy.y = y;
}

void	load_game(t_game *game)
{
	load_textures(game);
	spawn_enemy(game);
	mlx_loop_hook(game->mlx_ptr, &update, game);
	mlx_hook(game->window, 2, 1L << 0, &key_press, game);
	mlx_key_hook(game->window, handle_keypress, game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &close_game,
		game);
	mlx_loop(game->mlx_ptr);
}

void	window_cleaner(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game->img_enemy[i].img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->img_enemy[i].img_ptr);
		i++;
	}
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
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	i = 0;
	while (i < 6)
	{
		if (game->img_player[i].img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->img_player[i].img_ptr);
		i++;
	}
	window_cleaner(game);
}
