#include "utils/headers/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (!check_map(argv[1]))
		return (0);
	return (1);
}
