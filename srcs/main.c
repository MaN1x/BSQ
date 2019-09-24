/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:56:54 by mjoss             #+#    #+#             */
/*   Updated: 2019/08/22 04:24:49 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_func.h"
#include <stdlib.h>
#define PARAMS "tmp/params.txt"
#define MAP "tmp/map.txt"

int			params(char *h_char, char contain[3])
{
	int		fd;

	fd = 0;
	while (h_char[fd] >= '0' && h_char[fd] <= '9')
		fd++;
	contain[0] = h_char[fd];
	fd++;
	contain[1] = h_char[fd];
	fd++;
	contain[2] = h_char[fd];
	return (ft_atoi(h_char));
}

void		prepare(char *contain, int *height_width, int fd_in)
{
	int		fd;
	int		count;
	char	*h_char;

	count = 0;
	write_to_file(PARAMS, fd_in, '\n');
	write_to_file(MAP, fd_in, '\0');
	count = count_param();
	h_char = (char*)malloc((count) * sizeof(char));
	fd = open(PARAMS, O_RDONLY);
	read(fd, h_char, count);
	close(fd);
	height_width[0] = params(h_char, contain);
	if (height_width[0] == 0)
		return ;
	fd = open(MAP, O_RDONLY);
	count = ft_size();
	close(fd);
	free(h_char);
	height_width[1] = count / height_width[0];
}

void		solve_and_print(char *contain, int *height_width)
{
	char	**matr;

	matr = 0;
	matr = from_file_to_matr(MAP, matr, height_width);
	solve(matr, height_width, contain);
	print_matr(height_width, matr);
}

int			main(int argc, char **argv)
{
	int		height_width[2];
	int		i;
	int		fd;
	char	contain[3];

	i = 1;
	if (argc == 1)
	{
		prepare(contain, height_width, 0);
		if (check_map_valid(contain, height_width))
			solve_and_print(contain, height_width);
	}
	else
		while (i <= argc - 1)
		{
			fd = open(argv[i], O_RDONLY);
			prepare(contain, height_width, fd);
			close(fd);
			if (check_map_valid(contain, height_width))
				solve_and_print(contain, height_width);
			if (i != argc - 1)
				write(1, "\n", 1);
			i++;
		}
	return (0);
}
