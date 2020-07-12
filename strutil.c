#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int **g_main_grid;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return(i);
}

int ft_validate_src(char *str, int size)
{
	int i;

	if (ft_strlen(str) != (size * size) + (size * size) - 1)
	{
		printf("%s\n", "check2");
		printf("%d\n", ft_strlen(str));
		printf("%d\n", (size * size) + (size * size) - 1);
		return (0);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((i != 0) && (i % 2 == 1))
		{
			if (str[i] != ' ')
			{
				printf("%s\n", "check3");
				return (0);
			}
		}
		else
		{
			if (str[i] - '0' < 0 && str[i] - '0' > size + 1)
			{
				printf("%s\n", "check4");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

// Convert input string to int array
int *ft_convert_to_array(char *src, int size)
{
	static int *dest;
	int i;
	int j;

	dest = malloc(size * size * sizeof(int));
	i = 0;
	j = i;
	while (i < size * size)
	{
		dest[i] = src[i + j] - '0';
		i++;
		j++;
	}
	return (dest);
}

// Prints output in the required format
void	ft_print_grid(int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar((char)(g_main_grid[i][j] + '0'));
			if (j != size - 1)
				ft_putstr(" ");
			j++;
		}
		if (i != size - 1)
			ft_putstr("\n");
		i++;
	}
}
