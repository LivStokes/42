// rush01.h
#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

int		parse_clues(char *str, int *clues);
void	init_grid(int grid[4][4]);
void	print_grid(int grid[4][4]);
int		solve(int grid[4][4], int *clues, int row, int col);
int		is_valid(int grid[4][4], int row, int col, int num);
int		check_clues(int grid[4][4], int *clues);

#endif
