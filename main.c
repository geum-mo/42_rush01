#include <stdio.h>
#include <stdlib.h>

int		**g_ref_grid;
int		**g_main_grid;
int		g_size = 4; //need to update
int		ft_validate_src(char *str, int size);
int		*ft_convert_to_array(char *src, int size);
int		ft_fill_ref_grid(int *input, int size);
int 	ft_fill_main_grid(int size);
void	ft_putstr(char *str);
void	ft_print_grid(int size);

int		ft_solver(char *str, int size)
{
	int	*input_arr; // need to update [n+2][n+2]
	int len;

	len = sizeof(int *) * (size + 2) + sizeof(int) * (size + 2) * (size + 2); // Allocates memory to 2d array (n x n)
	g_ref_grid = (int **)malloc(len);
	input_arr = ft_convert_to_array(str, size);
	ft_fill_ref_grid(input_arr, size);
	ft_fill_main_grid(size);
	return (1);
}

int		main(int argc, char **argv)
{
	int len;
	int size;

	len = sizeof(int *) * g_size + sizeof(int) * g_size * g_size; // Allocates memory to 2d array (n x n)
	size = g_size;
	g_main_grid = (int **)malloc(len);
	if (argc != 2 || ft_validate_src(argv[1], size) == 0)
	{
		printf("%s\n", "check1");
		ft_putstr("Error\n");
		return (0);
	}
	ft_solver(argv[1], size);
	ft_print_grid(size);
	return (0);
}
