# ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 48

# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <time.h>

typedef struct s_image
{
    void    *img_ptr;
    int     width;
    int     height;
}			t_image;

typedef struct s_enemy
{
	void    *img_ptr;
    int		x;
    int		y;
    int		direction; // 1 for moving right, -1 for moving left
}           t_enemy;

typedef struct s_game
{
	char	**map;
	void	*mlx_ptr;
	void	*window;
	void	*img_wall;
	t_image	img_player[6];
	t_enemy	enemy;
	void	*img_collectible;
	void	*img_exit;
	void	*img_empty;
	int		player_y;
	int		player_x;
	int		map_width;
	int		map_height;
	int		collectibles;
	int		collected;
	int		moves;
	int     keys[65565];
}			t_game;

int			update(t_game *game);
int			close_game(t_game *game);
int			check_map_rectangular(t_game *game);
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
int			parse_map_lines(char *file, t_game *game);
int			handle_keypress(int keycode, t_game *game);

void		load_game(t_game *game);
void		render_map(t_game *game);
void		move_enemy(t_game *game);
void		cleanup_game(t_game *game);
void		load_textures(t_game *game);
void		init_collectibles(t_game *game);
void		display_move_count(t_game *game);
void		initialize_player_position(t_game *game);
void		move_player(t_game *game, int new_x, int new_y);

#endif