#include <stdio.h>

extern int **g_ref_grid;
extern int **g_main_grid;
int ft_recursive(void);

// Creates a reference grid with input numbers
int ft_fill_ref_grid(int *input, int size)
{
	int i;

	i = 0;

	while (i <= size * size - 1)
	{
		//printf("%s\n", "check10");
		if (i < size)
			g_ref_grid[0][i + 1] = input[i];
			//printf("%s\n", "check11");
		if (i >= size && i < size * 2)
			g_ref_grid[size + 1][i + 1 - size] = input[i];
			//printf("%s\n", "check12");
		if (i >= size * 2 && i < size * 3)
			g_ref_grid[i + 1- size * 2][0] = input[i];
			//printf("%s\n", "check13");
		if (i >= size * 3 && i < size * 4)
			g_ref_grid[i + 1 - size * 3][size + 1] = input[i];
			//printf("%s\n", "check14");
		//printf("%d,", input[i]);
		i++;
		//printf("%d\n", i);
	}
	return (0);
}

// Fills a main grid upfront with obvious values (split into 2 functons due to the length limit)
int ft_fill_loop1(int size, int x, int y)
{
	int i;

	i = 1;
	if (x == 0)
	{
		while(i <= size)
		{
			g_main_grid[x + i - 1][y] = i;
			//printf("%d,%d\n", x, y);
			i++;
		}
	}
	if (y == 0)
	{
		while(i <= size)
		{
			g_main_grid[x][y + i - 1] = i;
			//printf("%d,%d\n", x, y);
			i++;
		}
	}
	return (0);
}

int ft_fill_loop2(int size, int x, int y)
{
	int i;
	i = 1;

	if (x == size + 1)
	{
		while(i <= size)
		{
			g_main_grid[x - 1 - i][y] = i;
			i++;
		}
	}
	if (y == size + 1)
	{
		while(i <= size)
		{
			g_main_grid[x][y - 1- i] = i;
			i++;
		}
	}
	return (0);
}

int ft_fill_if(int size, int x, int y)
{
	if (x == 0)
		g_main_grid[x][y - 1] = size;
	if (y == 0)
		g_main_grid[x][y] = size;
	if (x == size + 1)
		g_main_grid[x - 1][y] = size;
	if (y == size + 1)
		g_main_grid[x][y - 1] = size;
	return (0);
}

int ft_fill_main_grid(int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	//printf("%s\n", "check12");
	while (i < size + 2) // n+2
	{
		while (j < size + 2)
		{
			if (g_ref_grid[i][j] == 1)
			{
				//printf("%s\n", "check13");
				ft_fill_if(size, i, j);
				//printf("%s\n", "check14");
			}
			if (g_ref_grid[i][j] == size) // 4 -> n
			{
				if (i == 0 || j == 0)
				{
					//printf("%s\n", "check15");
					ft_fill_loop1(size, i, j);
					//printf("%s\n", "check16");
				}
				if (i == size + 1 || j == size + 1) // 6 -> n + 2
				{
					//printf("%s\n", "check17");
					ft_fill_loop2(size, i, j);
					//printf("%s\n", "check18");
				}
			}
			j++;
		}
		i++;
	}
	ft_recursive();
	return (0);
}
