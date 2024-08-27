#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	char	**map;
	void	*mlx_ptr;
	void	*window;
	int		y;
	int		x;
	int		map_width;
	int		map_height;
}			t_game;

int			check_map(char *file, t_game *game);
void		handle_keypress(int keycode, t_game *game);
int			close_window(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		render_map(t_game *game);
void		cleanup_game(t_game *game);
void		ft_putstr(char *str);

#endif