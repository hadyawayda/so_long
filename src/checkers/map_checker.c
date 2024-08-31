/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:35:05 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/31 00:28:41 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/so_long.h"

// decrement map_width and line_len by 1 and add this condition in
// the while loop, if using windows or getting map not rectangular error:
// if (i == game->map_height - 1)
// 	line_len = line_len + 1;
int	check_map_rectangular(t_game *game)
{
	int	i;
	int	map_width;
	int	line_len;

	i = 1;
	if (game->map == NULL || game->map_height == 0)
		return (0);
	map_width = ft_strlen(game->map[0]);
	while (i < game->map_height)
	{
		line_len = ft_strlen(game->map[i]);
		if (line_len != map_width)
			return (0);
		i++;
	}
	game->map_width = map_width;
	return (1);
}

int	check_map_border(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	initialize_assets(t_game *game)
{
	int	x;
	int	y;

	game->collectibles = 0;
	game->collected = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->collectibles++;
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}

int	validate_map(t_game *game)
{
	if (!check_map_rectangular(game))
	{
		ft_printf("Error: Map is not rectangular\n");
		return (0);
	}
	if (!check_map_border(game))
	{
		ft_printf("Error: Map is not surrounded by walls\n");
		return (0);
	}
	initialize_assets(game);
	if (!check_path_to_exit(game))
	{
		ft_printf("Error: No valid path from player to exit\n");
		return (0);
	}
	return (1);
}
