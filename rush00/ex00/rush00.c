/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twatson <twatson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:30:28 by twatson           #+#    #+#             */
/*   Updated: 2025/03/30 16:50:45 by olstokes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	row(int x, char left, char mid, char right)
{
	int	column_index;

	if (x <= 0) 
		return ;
	ft_putchar(left);
	column_index = 1;
	while (column_index < x - 1)
	{
		ft_putchar(mid);
		column_index++;
	}
	if (x > 1)
		ft_putchar(right);
	ft_putchar('\n');
}

void	error_msg(void)
{
	char	*msg;

	msg = "Error: dimensions must be postitive integers.\n";
	while (*msg)
	{
		ft_putchar(*msg);
		msg++;
	}
}

void	rush(int x, int y)
{
	int	row_index;

	if (x <= 0 || y <= 0)
	{
		error_msg();
		return ;
	}
	row(x, 'o', '-', 'o');
	row_index = 1;
	while (row_index < y - 1)
	{
		row(x, '|', ' ', '|');
		row_index++;
	}
	if (y > 1)
		row(x, 'o', '-', 'o');
}
