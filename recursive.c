extern int **g_ref_grid;
extern int **g_main_grid;
extern int g_size;


int ft_count_jumps(int target, int x, int y, int z)
{
	int i;

	i = 0;
	while (i < size)
	{

	}
}

int ft_check_jumps(int x, int y, int z)
{
	//go right
	g_ref_grid[x][0];
	//go down
	g_ref_grid[0][y];
	//go up
	g_ref_grid[x][y + g_size];

	g_ref_grid[x + g_size][y];
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
	return (ft_check_jumps) ? 1 : 0;
}

int ft_recursive(void)
{
	int i;
	int j;
	int z;
	int flag;

	i = 0;
	z = 1;
	flag = 0;
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
						ft_recursive();
					}
					z++;
				}
				return (0);
			}
			j++;
		}
		//printf("%s\n", "check");
		i++;
		//printf("%d\n", i);
	}
	flag = 1;
	return (0);
}
