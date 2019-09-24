/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:54:14 by npetrell          #+#    #+#             */
/*   Updated: 2019/08/22 06:25:16 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft_func.h"
#define MAP "tmp/map.txt"

int			check_map_valid(char *contain, int *height_width)
{
	if (*height_width == 0)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	if (check_valid_head() == 0)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	else if (map_valid_symbol(contain) == 0)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	else if (map_valid_line(height_width) == 0)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	return (1);
}

int			ft_check_height(void)
{
	int		fd;
	int		i;
	char	buff[1];

	i = 0;
	fd = open(MAP, O_RDONLY);
	while (read(fd, buff, 1))
		if (buff[0] == '\n')
			i++;
	close(fd);
	return (i);
}

int			ft_size(void)
{
	int		i;
	int		fd;
	char	buff[1];

	i = 0;
	fd = open(MAP, O_RDONLY);
	while (read(fd, buff, 1))
		if (buff[0] != '\n')
			i++;
	close(fd);
	return (i);
}

int			map_valid_symbol(char *contain)
{
	int		fd;
	int		i;
	int		j;
	int		count;
	char	buff[1];

	i = 0;
	j = 0;
	count = ft_size();
	fd = open(MAP, O_RDONLY);
	while (read(fd, buff, 1))
	{
		if (buff[0] == contain[0])
			i++;
		if (buff[0] == contain[1])
			j++;
	}
	close(fd);
	if (i >= 1 && (i + j) == count)
	{
		return (1);
	}
	return (0);
}

int			map_valid_line(int *height_width)
{
	int		check_height;
	int		count;

	count = ft_size();
	check_height = ft_check_height();
	if ((count % check_height == 0) && (height_width[0] == check_height))
		return (1);
	return (0);
}
