/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:32:04 by mjoss             #+#    #+#             */
/*   Updated: 2019/08/21 18:16:58 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

int		check(int *coords, int size, char **matr, char *contain)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (i < size)
		{
			if (matr[coords[1] + j][coords[0] + i] == contain[1])
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int		check_size(int size, int *height_width, char **matr, char *contain)
{
	int	coords[2];

	coords[0] = 0;
	coords[1] = 0;
	while (coords[1] < height_width[0] - size + 1)
	{
		while (coords[0] < height_width[1] - size + 1)
		{
			if (check(coords, size, matr, contain) == 1)
			{
				fill(coords, size, matr, contain);
				return (1);
			}
			else
				coords[0]++;
		}
		coords[0] = 0;
		coords[1]++;
	}
	return (0);
}

void	fill(int *coords, int size, char **matr, char *contain)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (i < size)
		{
			matr[j + coords[1]][i + coords[0]] = contain[2];
			i++;
		}
		i = 0;
		j++;
	}
}

void	solve(char **matr, int *height_width, char *contain)
{
	int	f;
	int	size;

	f = 1;
	size = height_width[1];
	while (size >= 0 && f)
	{
		if (check_size(size, height_width, matr, contain) == 1)
			f = 0;
		else
			size--;
	}
}
