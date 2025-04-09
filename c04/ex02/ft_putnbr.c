/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olstokes <olstokes@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:07:33 by olstokes          #+#    #+#             */
/*   Updated: 2025/04/09 17:20:57 by olstokes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	n;
	
	n = nb;
	write(1, &n, 1);
}

int	main(void)
{
	nb = 10;
	ft_putnbr(n);
	return (0);
}
