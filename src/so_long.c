#include "utils/headers/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (!check_map(argv[1]))
		return (0);
	if (!check_map2(argv[1]))
		return (0);
	if (!check_map3(argv[1]))
		return (0);
	if (!check_map4(argv[1]))
		return (0);
	if (!check_map5(argv[1]))
		return (0);
	if (!check_map6(argv[1]))
		return (0);
	if (!check_map7(argv[1]))
		return (0);
	if (!check_map8(argv[1]))
		return (0);
	return (1);
}
