// solver.c
#include "rush01.h"

int	check_clues(int grid[4][4], int *clues); // implement later

int	is_valid(int grid[4][4], int row, int col, int num)
{
	for (int i = 0; i < 4; i++)
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
	return (1);
}

int	solve(int grid[4][4], int *clues, int row, int col)
{
	if (row == 4)
		return (check_clues(grid, clues));
	for (int num = 1; num <= 4; num++)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (col == 3)
			{
				if (solve(grid, clues, row + 1, 0))
					return (1);
			}
			else
			{
				if (solve(grid, clues, row, col + 1))
					return (1);
			}
			grid[row][col] = 0;
		}
	}
	return (0);
}
