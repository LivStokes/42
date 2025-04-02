/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01experiment1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olstokes <olstokes@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:57:40 by olstokes          #+#    #+#             */
/*   Updated: 2025/03/29 17:08:36 by olstokes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

extern void	ft_putchar(char c);

void	print_line(int x, char first, char mid, char last)
{
	int j;

	j = 0;
	while (j < x)
	{
		if (j == 0)
			ft_putchar(first);
		else if (j == x - 1)
			ft_putchar(last);
		else
			ft_putchar(mid);
		j++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int i;

	if (x <= 0 || y <= 0)
		return ;
	i = 0;
	while (i < y)
	{
		if (i == 0)
			print_line(x, '/', '*', '\\');
		else if (i == y - 1)
			print_line(x, '\\', '*', '/');
		else
			print_line(x, '*', ' ', '*');
		i++;
	}
}
