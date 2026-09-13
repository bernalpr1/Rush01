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

int	ft_check_lc(int grid[4][4], int l, int c, int n);
int	ft_top(int grid[4][4], int c, int view[4][4]);
int	ft_bottom(int grid[4][4], int c, int view[4][4]);
int	ft_left(int grid[4][4], int l, int view[4][4]);
int	ft_right(int grid[4][4], int l, int view[4][4]);

int	ft_is_valid(int grid[4][4], int l, int c, int view[4][4])
{
	if (c == 3 && !ft_left(grid, l, view))
		return (0);
	if (c == 3 && !ft_right(grid, l, view))
		return (0);
	if (l == 3 && !ft_top(grid, c, view))
		return (0);
	if (l == 3 && !ft_bottom(grid, c, view))
		return (0);
	return (1);
}

int	ft_solver(int grid[4][4], int view[4][4], int l, int c)
{

}


