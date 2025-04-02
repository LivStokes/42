/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaus <mbaus@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:39:14 by mbaus             #+#    #+#             */
/*   Updated: 2025/03/30 14:48:42 by mbaus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y);

void	print_first_row(int x)
{
	int 	col;

	col = 0;
	while (col < x)
	{
		if (col == 0 || col == x - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
		col++;
	}
	ft_putchar('\n');
}

void	print_middle_row(int x)
{
	int col;
	col = 0;
	while (col < x)
	{
		if (col == 0 || col == x - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
		col++;
	}
	ft_putchar('\n');
}

void	print_last_row(int x)
{
	int col;
	col = 0;
	while (col < x)
	{
		if (col == 0 || col == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		col++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int row;

	if (x <= 0 || y <= 0)
		return;
	print_first_row(x);
	row = 1;
	while(row < y - 1)
	{
		print_middle_row(x);
		row++;
	}
	if (y > 1)
		print_last_row(x);
}
