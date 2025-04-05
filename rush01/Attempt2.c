#include <unistd.h>
#include <stdlib.h>

int     parse_clues(char *str, int *clues);
void    init_grid(int grid[4][4]);
void    print_grid(int grid[4][4]);
int     solve(int grid[4][4], int *clues, int row, int col);
int     is_valid(int grid[4][4], int row, int col, int num);
int     check_clues(int grid[4][4], int *clues);

int main(int argc, char **argv)
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

void init_grid(int grid[4][4])
{
    int i = 0;
    while (i < 4)
    {
        int j = 0;
        while (j < 4)
        {
            grid[i][j] = 0;
            j++;
        }
        i++;
    }
}

void print_grid(int grid[4][4])
{
    int i = 0;
    while (i < 4)
    {
        int j = 0;
        while (j < 4)
        {
            char c = grid[i][j] + '0';
            write(1, &c, 1);
            if (j < 3)
                write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

int parse_clues(char *str, int *clues)
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

int check_clues(int grid[4][4], int *clues)
{
    int i = 0;
    while (i < 4)
    {
        int left = 0, right = 0, top = 0, bottom = 0;

        // Check row from left to right
        int max = 0, visible = 0;
        int j = 0;
        while (j < 4)
        {
            if (grid[i][j] > max)
            {
                max = grid[i][j];
                visible++;
            }
            j++;
        }
        if (visible != clues[i])
            return (0);

        // Check row from right to left
        max = 0;
        visible = 0;
        j = 3;
        while (j >= 0)
        {
            if (grid[i][j] > max)
            {
                max = grid[i][j];
                visible++;
            }
            j--;
        }
        if (visible != clues[4 + i])
            return (0);

        i++;
    }

    // Checking columns
    int col = 0;
    while (col < 4)
    {
        int top_visible = 0, bottom_visible = 0, max = 0, visible = 0;

        // Check top to bottom
        int row = 0;
        while (row < 4)
        {
            if (grid[row][col] > max)
            {
                max = grid[row][col];
                visible++;
            }
            row++;
        }
        if (visible != clues[8 + col])
            return (0);

        // Check bottom to top
        max = 0;
        visible = 0;
        row = 3;
        while (row >= 0)
        {
            if (grid[row][col] > max)
            {
                max = grid[row][col];
                visible++;
            }
            row--;
        }
        if (visible != clues[12 + col])
            return (0);

        col++;
    }
    return (1);
}

int is_valid(int grid[4][4], int row, int col, int num)
{
    int i = 0;
    while (i < 4)
    {
        if (grid[row][i] == num || grid[i][col] == num)
            return (0);
        i++;
    }
    return (1);
}

int solve(int grid[4][4], int *clues, int row, int col)
{
    if (row == 4)
        return (check_clues(grid, clues));
    int num = 1;
    while (num <= 4)
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
        num++;
    }
    return (0);
}
