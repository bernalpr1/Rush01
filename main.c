/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berpinhe <berpinhe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 16:03:39 by berpinhe          #+#    #+#             */
/*   Updated: 2026/09/12 18:46:13 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
int		ft_parse_views(char *str, int view[4][4]);
int		ft_solver(int grid[4][4], int view[4][4], int l, int c);
void	ft_print_grid(int grid[4][4]);

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	ft_parse_views(char *str, int view[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (*str >= '1' && *str <= '4')
				view[i][j] = *str - '0';
			else
				return (0);
			str++;
			if (*str == ' ')
				str++;
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

void	ft_init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			grid[i][j++] = 0;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	grid[4][4];
	int	view[4][4];

	if (ac != 2 || ft_strlen(av[1]) != 31)
		return (ft_error());
	if (!ft_parse_views(av[1], view))
		return (ft_error());
	ft_init_grid(grid);
	if (!ft_solver(grid, view, 0, 0))
		return (ft_error());
	ft_print_grid(grid);
	return (0);
}
