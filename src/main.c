/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:35:32 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/29 19:48:32 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/headers/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.moves = 0;
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}
	if (!parse_map_lines(argv[1], &game) || !validate_map(&game))
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		return (1);
	}
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);
	game.window = mlx_new_window(game.mlx_ptr, game.map_width * TILE_SIZE,
			game.map_height * TILE_SIZE, "so_long");
	if (!game.window)
		return (1);
	load_game(&game);
	return (0);
}
