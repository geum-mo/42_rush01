#include <unistd.h>
#include <stdio.h>

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

int ft_check_src(char *str)
{
	int i;

	if (ft_strlen(str) != 31)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (i != 0 && i % 2 == 1)
		{
			if (str[i] != ' ')
			{
				printf("\%s\n", "check1");
				printf("\%c\n", str[i]);
				return (0);
			}
		}
		else
		{
			if (str[i] - '0' < 0 && str[i] - '0' > 5)
			{
				printf("\%s\n", "check2");
				printf("\%c\n", str[i]);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int *ft_convert_to_array(int *dest, char *src)
{
	int i;
	int j;

	if (ft_check_src(src) == 0)
		return (0);
	i = 0;
	j = i;
	while (i < 16)
	{
		dest[i] = src[i + j] - '0';
		i++;
		j++;
	}
	return (dest);
}

int main(int argc, char **argv)
{
	int i;
	int array[16];

	// Raises an exception when no argument is passed
	if (argc != 2)
	{
		ft_putstr("Error\n");
	}
	// Convers string to int array
	if (ft_convert_to_array(array, argv[1]) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	// Tests the converting function
	i = 0;
	while (i < 16)
	{
		printf("\%d\n", array[i]);
		i++;
	}
}
