// isspace whitespace characters - decimal values 9\t, 10\n, 11\v, 12\f, 13\r, 32is space.
// 
//

#include <ctype.h>

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    int minus_count = 0;

    // Step 1: Skip leading whitespace
    while (isspace(str[i]))
        i++;

    // Step 2: Count '+' and '-' signs
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            minus_count++;
        i++;
    }

    // Determine final sign
    if (minus_count % 2 != 0)
        sign = -1;

    // Step 3: Process digits
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    // Step 4: Apply sign and return
    return result * sign;
}

#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 2)
        printf("%d\n", ft_atoi(argv[1]));
    return 0;
}

