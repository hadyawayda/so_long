/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:35:27 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/29 20:43:18 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/so_long.h"

void	load_player(t_game *game, int width, int height)
{
	int		i;
	char	*file_paths[6];

	file_paths[0] = "./assets/Player_Resized_1.xpm";
	file_paths[1] = "./assets/Player_Resized_2.xpm";
	file_paths[2] = "./assets/Player_Resized_3.xpm";
	file_paths[3] = "./assets/Player_Resized_4.xpm";
	file_paths[4] = "./assets/Player_Resized_5.xpm";
	file_paths[5] = "./assets/Player_Resized_6.xpm";
	i = 0;
	while (i < 6)
	{
		game->img_player[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				file_paths[i], &width, &height);
		game->img_player[i].width = width;
		game->img_player[i].height = height;
		i++;
	}
}

void	load_enemy(t_game *game, int width, int height)
{
	int		i;
	char	*file_paths[6];

	file_paths[0] = "./assets/Skeleton_1.xpm";
	file_paths[1] = "./assets/Skeleton_2.xpm";
	file_paths[2] = "./assets/Skeleton_3.xpm";
	file_paths[3] = "./assets/Skeleton_4.xpm";
	file_paths[4] = "./assets/Skeleton_5.xpm";
	file_paths[5] = "./assets/Skeleton_6.xpm";
	i = 0;
	while (i < 6)
	{
		game->img_enemy[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				file_paths[i], &width, &height);
		game->img_enemy[i].width = width;
		game->img_enemy[i].height = height;
		i++;
	}
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	width = 48;
	height = 48;
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/FarmLand_Tile.xpm", &width, &height);
	game->img_empty = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/Grass_Middle_Resized.xpm", &width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/Chest_Resized.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/wooden_door_b.xpm", &width, &height);
	load_player(game, width, height);
	load_enemy(game, width, height);
}
