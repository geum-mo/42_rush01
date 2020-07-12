#include <stdio.h>
#include <stdlib.h>

extern int **g_ref_grid;
extern int **g_main_grid;
extern int g_size;
extern char *input_str;

void	ft_print_grid(int size);
int		ft_solver(char *str, int size);

int ft_check_right_jumps(void)
{
	int i;
	int j;
	int k;
	int count;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		count = 0;
		while (j < g_size - 1)
		{
			k = j + 1;
			while (k < g_size)
			{
				//printf("i = %d, j = %d, k = %d, value is %d vs %d\n", i, j ,k, g_main_grid[i][j], g_main_grid[i][k]);
				//printf("%d\n", g_main_grid[i][k]);
				if (g_main_grid[i][j] < g_main_grid[i][k])
				{
					count++;
					break ;
				}
				k++;
			}
			j++;
		}
		if (g_ref_grid[i + 1][0] != count)
			return (0);
		i++;
	}
	return (1);
}

int ft_check_down_jumps(void)
{
	int i;
	int j;
	int k;
	int count;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		count = 0;
		while (j < g_size - 1)
		{
			k = j + 1;
			while (k < g_size)
			{
				if (g_main_grid[j][i] < g_main_grid[k][i])
				{
					count++;
					break ;
				}
				k++;
			}
			j++;
		}
		if (g_ref_grid[0][i + 1] != count)
			return (0);
		i++;
	}
	return (1);
}

int ft_check_left_jumps(void)
{
	int i;
	int j;
	int k;
	int count;

	i = 1;
	while (i <= g_size)
	{
		j = g_size - 1;
		count = 0;
		while (j < (g_size - 1) * -1)
		{
			k = j - 1;
			while (k < g_size * -1)
			{
				//printf("i = %d, j = %d, k = %d, value is %d vs %d\n", i, j ,k, g_main_grid[i][j], g_main_grid[i][k]);
				//printf("%d\n", g_main_grid[i][k]);
				if (g_main_grid[i][j] < g_main_grid[i][k])
				{
					count++;
					break ;
				}
				k--;
			}
			j--;
		}
		if (g_ref_grid[i - 1][g_size] != count)
			return (0);
		i++;
	}
	return (1);
}

int ft_check_up_jumps(void)
{
	int i;
	int j;
	int k;
	int count;

	i = 1;
	while (i <= g_size)
	{
		j = g_size - 1;
		count = 0;
		while (j < (g_size - 1) * -1)
		{
			k = j - 1;
			while (k < g_size * -1)
			{
				if (g_main_grid[j][i] < g_main_grid[k][i])
				{
					count++;
					break ;
				}
				k--;
			}
			j--;
		}
		if (g_ref_grid[g_size][i - 1] != count)
			return (0);
		i++;
	}
	return (1);
}

int ft_check_all_jumps(void)
{
	//goes right
	if (ft_check_right_jumps() != 1)
		return (0);
	printf("%s\n", "check2");
	//goes down
	if (ft_check_down_jumps() != 1)
		return (0);
	printf("%s\n", "check3");
	//goes left
	if (ft_check_left_jumps() != 1)
		return (0);
	printf("%s\n", "check4");
	//goes up
	if (ft_check_up_jumps() != 1)
		return (0);
	printf("%s\n", "check5");
	return (1);
}

int ft_check_rules(int x, int y, int z)
{
	//printf("%d, %d", x, y);
	int i;
	int j;

	i = 0;
	j = 0;
	// Checks duplicates in the row
	while (i < g_size)
	{
		if (g_main_grid[x][i] == z)
		{
			return (0);
		}
		i++;
	}
	// Checks duplicates in the column
	while (j < g_size)
	{
		if (g_main_grid[j][y] == z)
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int ft_recursive(void)
{
	int i;
	int j;
	int z;

	i = 0;
	z = 1;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			//printf("%d\n", main_grid[i][j]);
			if (g_main_grid[i][j] == 0)
			{
				//printf("%d, %d", i, j);
				z = 1;
				while (z <= g_size)
				{
					if (ft_check_rules(i, j, z) == 1)
					{
						g_main_grid[i][j] = z;
					}
					z++;
				}
			}
			j++;
		}
		//printf("%s\n", "check");
		i++;
		//printf("%d\n", i);
	}
	//free(g_ref_grid);
	//free(g_main_grid);
	printf("check all jump is %d\n", ft_check_all_jumps());
	if (ft_check_all_jumps() != 1)
	{
		ft_solver(input_str, g_size);
	}
	ft_print_grid(g_size);
	return (0);
}
