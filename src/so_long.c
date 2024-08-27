#include "utils/headers/so_long.h"

int	main(int argc, char **argv)
{
	void *mlx;
    void *win;

    mlx = mlx_init();  // Initialize the MiniLibX connection
    if (!mlx)
        return (1);
    
    win = mlx_new_window(mlx, 800, 600, "so_long");  // Create a new window
    if (!win)
    {
        // Handle error if window creation fails
        return (1);
    }

    mlx_loop(mlx);  // Enter the MiniLibX event loop to keep the window open
    return (0);
}
