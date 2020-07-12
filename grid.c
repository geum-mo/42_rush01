extern int **g_ref_grid;
extern int **g_main_grid;
int ft_recursive(void);

// Creates a reference grid with input numbers
int ft_fill_ref_grid(int *input, int size)
{
	int i = 0;
	while (i < size * size)
	{
		if (i < size)
			g_ref_grid[0][i] = input[i];
		if (i >= size && i < size * 2)
			g_ref_grid[size + 2][i] = input[i];
		if (i >= size * 2 && i < size * 3)
			g_ref_grid[i][0] = input[i];
		if (i >= size * 3 && i < size * 4)
			g_ref_grid[i][size + 2] = input[i];
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
			g_main_grid[x + i][y] = i;
			i++;
		}
	}
	if (y == 0)
	{
		while(i <= size)
		{
			g_main_grid[x][y + i] = i;
			i++;
		}
	}
	return (0);
}

int ft_fill_loop2(int size, int x, int y)
{
	int i;
	i = 1;

	if (x == size + 2)
	{
		while(i <= size)
		{
			g_main_grid[x - i][y] = i;
			i++;
		}
	}
	if (y == size + 2)
	{
		while(i <= size)
		{
			g_main_grid[x][y - i] = i;
			i++;
		}
	}
	return (0);
}

int ft_fill_if(int size, int x, int y)
{
	if (x == 0)
		g_main_grid[x + 1][y] = size;
	if (y == 0)
		g_main_grid[x][y + 1] = size;
	if (x == size + 2)
		g_main_grid[x - 1][y] = size;
	if (y == size + 2)
		g_main_grid[x][y - 1] = size;
	return (0);
}

int ft_fill_main_grid(int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size + 2) // n+2
	{
		while (j < size + 2)
		{
			if (g_ref_grid[i][j] == 1)
				ft_fill_if(size, i, j);
			if (g_ref_grid[i][j] == size) // 4 -> n
			{
				if (i == 0 || j == 0)
					ft_fill_loop1(size, i, j);
				if (i == size + 2 || j == size + 2) // 6 -> n + 2
					ft_fill_loop2(size, i, j);
			}
			j++;
		}
		i++;
	}
	ft_recursive();
	return (0);
}
