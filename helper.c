/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berpinhe <berpinhe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:21:05 by berpinhe          #+#    #+#             */
/*   Updated: 2026/09/13 17:21:07 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ezhelp4(int grid[4][4], int dir, int pos)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (dir == 0)
			grid[i][pos] = i + 1;
		else if (dir == 1)
			grid[3 - i][pos] = i + 1;
		else if (dir == 2)
			grid[pos][i] = i + 1;
		else if (dir == 3)
			grid[pos][3 - i] = i + 1;
		i++;
	}
}

void	ft_ezhelp1(int grid[4][4], int dir, int pos)
{
	if (dir == 0)
		grid[0][pos] = 4;
	else if (dir == 1)
		grid[3][pos] = 4;
	else if (dir == 2)
		grid[pos][0] = 4;
	else if (dir == 3)
		grid[pos][3] = 4;
}

void	ft_ezfill(int grid[4][4], int view[4][4])
{
	int	dir;
	int	pos;

	dir = 0;
	while (dir < 4)
	{
		pos = 0;
		while (pos < 4)
		{
			if (view[dir][pos] == 4)
				ft_ezhelp4(grid, dir, pos);
			if (view[dir][pos] == 1)
				ft_ezhelp1(grid, dir, pos);
			pos++;
		}
		dir++;
	}
}

void	ft_print_grid(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	ft_check_lc(int grid[4][4], int l, int c, int n)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[i][c] == n)
			return (0);
		if (grid[l][i] == n)
			return (0);
		i++;
	}
	return (1);
}
