/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olstokes <olstokes@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:19:02 by olstokes          #+#    #+#             */
/*   Updated: 2025/04/07 16:10:55 by olstokes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	printf("%d\n", ft_str_is_printable("Meow"));
	printf("%d\n", ft_str_is_printable("12345"));
	printf("%d\n", ft_str_is_printable(""));
	printf("%d\n", ft_str_is_printable(" "));
	printf("%d\n", ft_str_is_printable("\n"));
	return (0);
}
*/
