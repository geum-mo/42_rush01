#include <stdio.h>
#include <stdlib.h>

int		**g_ref_grid;
int		**g_main_grid;
char	*input_str;
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
	int i;

	input_str = str;
	i = 0;
	g_ref_grid = NULL;
	//printf("%s\n", "check6");
	//printf("%s\n", "check7");
	g_ref_grid = (int **)malloc(sizeof(int*)*(size + 2));
	while (i< size + 2)
	{
		g_ref_grid[i] = (int*)malloc(sizeof(int)*(size + 2));
		i++;
	}

	//printf("%s\n", "check8");
	input_arr = ft_convert_to_array(str, size);
	//printf("%s\n", "check9");
	ft_fill_ref_grid(input_arr, size);
	//printf("%s\n", "check11");
	ft_fill_main_grid(size);
	ft_print_grid(size);
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	int size;

	i = 0;
	size = g_size;
	g_main_grid = NULL;
	g_main_grid = (int **)malloc(sizeof(int*)*(size));
	while (i< size)
	{
		g_main_grid[i] = (int*)malloc(sizeof(int)*(size));
		i++;
	}

	//printf("%s\n", "check0");
	if (argc != 2 || ft_validate_src(argv[1], size) == 0)
	{
		//printf("%s\n", "check1");
		ft_putstr("Error\n");
		return (0);
	}
	//printf("%s\n", "check5");
	ft_solver(argv[1], size);
	return (0);
}
