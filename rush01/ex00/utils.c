/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatil <apatil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:12:22 by apatil            #+#    #+#             */
/*   Updated: 2025/04/06 16:06:37 by olstokes         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

void	ft_swap(char *a, char *b);
int     ft_strlen(char *str);
int is_space(char *str);
void	ft_putstr(char *str);
int	ft_strcmp(char *s1, char *s2);
void	error_msg(void);

void	ft_rev_array(char *arr)
{
	int	iter;
    int size;

    size = ft_strlen(arr);

	iter = 0;
	while (iter < size / 2)
	{
		ft_swap(&arr[iter], &arr[size - iter - 1]);
		iter++;
	}
}

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while(*str)
    {
        len++;
    }
    return (len);
}

int is_space(char *str)
{
    return (0);
}

void	ft_putstr(char *str)
{
	int	size;
	
	size = ft_strlen(str);
	write(1, str, size);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	// while the two strings are equal and S1 does not reach the end
	while (s1[i] == s2[i] && s1[i])
	{
		// While they are the same, the counter is added
		i++;
	}
	// In the end, if they are equal or different, the value will be returned
	return (s1[i] - s2[i]);
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


