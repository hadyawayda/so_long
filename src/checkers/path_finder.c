/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:34:26 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/29 21:50:55 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/so_long.h"

void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		return ;
	}
	map[y][x] = 'V';
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x, y - 1, game);
	flood_fill(map, x, y + 1, game);
}

void	free_map_copy(char **map_copy, t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_height)
		free(map_copy[i]);
	free(map_copy);
}

void	flood_fill_map(char **map_copy, t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_height)
		map_copy[i] = ft_strdup(game->map[i]);
	flood_fill(map_copy, game->player_x, game->player_y, game);
}

int	check_map_copy(char **map_copy, t_game *game)
{
	int	y;
	int	x;
	int	result;

	y = 0;
	result = 1;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'E' && map_copy[y][x] != 'V')
			{
				result = 0;
				break ;
			}
			x++;
		}
		if (result == 0)
			break ;
		y++;
	}
	return (result);
}

int	check_path_to_exit(t_game *game)
{
	char	**map_copy;
	int		result;

	result = 1;
	map_copy = malloc(sizeof(char *) * (game->map_height + 1));
	flood_fill_map(map_copy, game);
	result = check_map_copy(map_copy, game);
	free_map_copy(map_copy, game);
	return (result);
}
