/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berpinhe <berpinhe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:40:46 by berpinhe          #+#    #+#             */
/*   Updated: 2026/09/12 19:54:59 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_check_lc(int grid[4][4], int l, int c, int n);
int			ft_top(int grid[4][4], int c, int view[4][4]);
int			ft_bottom(int grid[4][4], int c, int view[4][4]);
int			ft_left(int grid[4][4], int l, int view[4][4]);
int			ft_right(int grid[4][4], int l, int view[4][4]);
void		ft_ezfill(int grid[4][4], int view[4][4]);
int			ft_solver(int grid[4][4], int view[4][4], int l, int c);

int	ft_is_valid(int grid[4][4], int l, int c, int view[4][4])
{
	if (c == 3)
	{
		if (!ft_left(grid, l, view) || !ft_right(grid, l, view))
			return (0);
	}
	if (l == 3)
	{
		if (!ft_top(grid, c, view) || !ft_bottom(grid, c, view))
			return (0);
	}
	return (1);
}

int	ft_next(int grid[4][4], int view[4][4], int l, int c)
{
	if (c == 3)
		return (ft_solver(grid, view, l + 1, 0));
	return (ft_solver(grid, view, l, c + 1));
}

int	ft_solver(int grid[4][4], int view[4][4], int l, int c)
{
	int	n;

	if (l == 0 && c == 0)
		ft_ezfill(grid, view);
	if (l == 4)
		return (1);
	if (grid[l][c] != 0)
	{
		if (ft_is_valid(grid, l, c, view))
			return (ft_next(grid, view, l, c));
		return (0);
	}
	n = 1;
	while (n <= 4)
	{
		if (ft_check_lc(grid, l, c, n))
		{
			grid[l][c] = n;
			if (ft_is_valid(grid, l, c, view) && ft_next(grid, view, l, c))
				return (1);
			grid[l][c] = 0;
		}
		n++;
	}
	return (0);
}
