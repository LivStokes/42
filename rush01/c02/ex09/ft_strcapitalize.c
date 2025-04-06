#include <unistd.h>

// Function to convert the first letter of each word to uppercase and others to lowercase
char *ft_strcapitalize(char *str)
{
    int i = 0;
    int is_new_word = 1;  // Flag to track the start of a word

    while (str[i] != '\0')
    {
        // If the current character is a letter
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (is_new_word)  // If it's the first letter of a word
            {
                if (str[i] >= 'a' && str[i] <= 'z')  // Convert to uppercase if it's lowercase
                    str[i] = str[i] - ('a' - 'A');
                is_new_word = 0;  // Mark that we are inside a word now
            }
            else  // If it's not the first letter, make it lowercase
            {
                if (str[i] >= 'A' && str[i] <= 'Z')  // Convert to lowercase if it's uppercase
                    str[i] = str[i] + ('a' - 'A');
            }
        }
        else
        {
            is_new_word = 1;  // Mark the next alphanumeric character as the start of a new word
        }
        i++;
    }

    return str;
}

// Function to output a single character
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Function to output a string
void ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}

// Main function to demonstrate the ft_strcapitalize function
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        write(1, "usage: ./ft_strcapitalize \"string\"\n", 33);
        return (1);
    }
    
    ft_putstr(ft_strcapitalize(argv[1]));  // Capitalize and print the input string
    write(1, "\n", 1);  // Print a newline
    return (0);
}

