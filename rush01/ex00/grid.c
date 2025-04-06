#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	char c = n + '0';
	ft_putchar(c);
}

// x by y grid
void	write_grid(int x, int y)
{
	int **grid;
	int row = 0;

// Allocate grid
	grid = malloc(sizeof(int *) * y);
	while (row < y)
	{
		int col = 0;
		grid[row] = malloc(sizeof(int) * x);
		while (col < x)
		{
			// Fill with a pattern (for demo purposes)
			grid[row][col] = (col + row) % x + 1;
			col++;
		}
		row++;
	}

// Print grid
	row = 0;
	while (row < y)
	{
		int col = 0;
		while (col < x)
		{
			ft_putnbr(grid[row][col]);
			if (col < x - 1)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}

// Free memory
	row = 0;
	while (row < y)
		free(grid[row++]);
	free(grid);
}

int	main(void)
{
	int x = 4; // width
	int y = 4; // height

	write_grid(x, y);
	return (0);
}

