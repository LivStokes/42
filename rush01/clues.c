// check_clues.c
#include "rush01.h"

int	count_visible(int *line)
{
	int count = 1;
	int max = line[0];
	for (int i = 1; i < 4; i++)
	{
		if (line[i] > max)
		{
			count++;
			max = line[i];
		}
	}
	return count;
}

void	get_col(int grid[4][4], int col_idx, int *col)
{
	for (int i = 0; i < 4; i++)
		col[i] = grid[i][col_idx];
}

void	reverse(int *line)
{
	for (int i = 0; i < 2; i++)
	{
		int tmp = line[i];
		line[i] = line[3 - i];
		line[3 - i] = tmp;
	}
}

int	check_clues(int grid[4][4], int *clues)
{
	int line[4];
	int i;

	// Top clues
	for (i = 0; i < 4; i++)
	{
		get_col(grid, i, line);
		if (count_visible(line) != clues[i])
			return (0);
	}

	// Bottom clues
	for (i = 0; i < 4; i++)
	{
		get_col(grid, i, line);
		reverse(line);
		if (count_visible(line) != clues[4 + i])
			return (0);
	}

	// Left clues
	for (i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			line[j] = grid[i][j];
		if (count_visible(line) != clues[8 + i])
			return (0);
	}

	// Right clues
	for (i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			line[j] = grid[i][j];
		reverse(line);
		if (count_visible(line) != clues[12 + i])
			return (0);
	}

	return (1);
}
