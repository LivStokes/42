#include <unistd.h>
#include <stdlib.h>

#define SIZE 4

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		count;
	int		b[10];

	count = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == 0)
	{
		ft_putchar(nb + 48);
	}
	while (nb > 0)
	{
		b[count] = nb % 10;
		count++;
		nb /= 10;
	}
	while (count > 0)
	{
		count--;
		ft_putchar(b[count] + 48);
	}
}

void	print_grid(int grid[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			ft_putnbr(grid[i][j]);
			if (j < SIZE - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int	parse_clues(char *str, int *clues)
{
	int i = 0;
	while (*str)
	{
		if (*str >= '1' && *str <= '4')
			clues[i++] = *str - '0';
		else if (*str != ' ')
			return (0);
		str++;
	}
	return (i == 16);
}

int	is_valid(int grid[SIZE][SIZE], int row, int col, int num)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
	}
	return (1);
}

int	check_visibility(int grid[SIZE][SIZE], int *clues)
{
	int i, j, max, visible;
	
	// Check top visibility for each column
	for (j = 0; j < SIZE; j++)
	{
		max = 0;
		visible = 0;
		for (i = 0; i < SIZE; i++)
		{
			if (grid[i][j] > max)
			{
				max = grid[i][j];
				visible++;
			}
		}
		if (visible != clues[j]) return (0); // Top view check
	}
	
	// Check bottom visibility for each column
	for (j = 0; j < SIZE; j++)
	{
		max = 0;
		visible = 0;
		for (i = SIZE - 1; i >= 0; i--)
		{
			if (grid[i][j] > max)
			{
				max = grid[i][j];
				visible++;
			}
		}
		if (visible != clues[SIZE + j]) return (0); // Bottom view check
	}

	// Check left visibility for each row
	for (i = 0; i < SIZE; i++)
	{
		max = 0;
		visible = 0;
		for (j = 0; j < SIZE; j++)
		{
			if (grid[i][j] > max)
			{
				max = grid[i][j];
				visible++;
			}
		}
		if (visible != clues[SIZE * 2 + i]) return (0); // Left view check
	}

	// Check right visibility for each row
	for (i = 0; i < SIZE; i++)
	{
		max = 0;
		visible = 0;
		for (j = SIZE - 1; j >= 0; j--)
		{
			if (grid[i][j] > max)
			{
				max = grid[i][j];
				visible++;
			}
		}
		if (visible != clues[SIZE * 3 + i]) return (0); // Right view check
	}

	return (1);
}

int	solve(int grid[SIZE][SIZE], int *clues, int row, int col)
{
	if (row == SIZE)
	{
		if (check_visibility(grid, clues))
		{
			print_grid(grid);
			return (1);
		}
		return (0);
	}

	for (int num = 1; num <= SIZE; num++)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (col == SIZE - 1)
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

int	main(int argc, char **argv)
{
	int clues[16];
	int grid[SIZE][SIZE];

	if (argc != 2 || !parse_clues(argv[1], clues))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	
	// Initialize the grid with 0 (empty)
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			grid[i][j] = 0;

	if (!solve(grid, clues, 0, 0))
		write(1, "Error\n", 6);
	return (0);
}
