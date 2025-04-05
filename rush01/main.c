// main.c
#include "rush01.h"

int	main(int argc, char **argv)
{
	int clues[16];
	int grid[4][4];

	if (argc != 2 || !parse_clues(argv[1], clues))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init_grid(grid);
	if (solve(grid, clues, 0, 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
