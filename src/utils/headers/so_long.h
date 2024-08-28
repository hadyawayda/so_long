#ifndef SO_LONG_H
# define SO_LONG_H

#define TILE_SIZE 48

# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_game
{
	char	**map;
	void	*textures[5];
	void	*mlx_ptr;
	void	*window;
	int		player_y;
	int		player_x;
	int		map_width;
	int		map_height;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	void	*img_empty;
}			t_game;

int			check_map(char *file, t_game *game);
int			handle_keypress(int keycode, t_game *game);
int			close_window(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		render_map(t_game *game);
void		load_textures(t_game *game);
void		cleanup_game(t_game *game);
void		ft_putstr(char *str);

#endif