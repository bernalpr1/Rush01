int	ft_top(int grid[4][4], int c, int view[4][4])
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][c] > max)
		{
			count++;
			max = grid[i][c];
		}
		i++;
	}
	return (count == view[0][c]);
}

int	ft_bottom(int grid[4][4], int c, int view[4][4])
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[i][c] > max)
		{
			count++;
			max = grid[i][c];
		}
		i--;
	}
	return (count == view[1][c]);
}

int	ft_left(int grid[4][4], int l, int view[4][4])
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[l][i] > max)
		{
			count++;
			max = grid[l][i];
		}
		i++;
	}
	return (count == view[2][l]);
}

int	ft_right(int grid[4][4], int l, int view[4][4])
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[l][i] > max)
		{
			count++;
			max = grid[l][i];
		}
		i--;
	}
	return (count == view[3][l]);
}
