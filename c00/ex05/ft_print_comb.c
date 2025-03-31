/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olstokes <olstokes@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:32:36 by olstokes          #+#    #+#             */
/*   Updated: 2025/03/31 14:32:44 by olstokes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = '0';
	while (a++ <= '7')
	{
		b = a + '1';
		while (b++ <= '8')
		{
			c = b + '1';
			while (c++ <= '9');
				{
					ft_putchar(a, b, c);
					ft_putchar(' ');
				}
			}
		}
	}
}
/*
int	main(void)
{
	ft_print_comb();
	ft_putchar('\n');
	return (0);
}
*/
