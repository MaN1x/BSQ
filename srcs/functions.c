/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:56:02 by npetrell          #+#    #+#             */
/*   Updated: 2019/08/22 01:35:48 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_func.h"
#include <stdlib.h>

char	**from_file_to_matr(char *path, char **matr, int *height_width)
{
	int		fd;
	int		j;
	int		i;
	char	c[1];

	i = 0;
	j = -1;
	fd = open(path, O_RDONLY);
	matr = (char**)malloc(height_width[0] * sizeof(char**));
	while (++j < height_width[0])
	{
		matr[j] = (char*)malloc(height_width[1] * sizeof(char*));
		while (i < height_width[1])
		{
			read(fd, c, 1);
			if (c[0] != '\n')
			{
				matr[j][i] = c[0];
				i++;
			}
		}
		i = 0;
	}
	close(fd);
	return (matr);
}

void	print_matr(int *height_width, char **matr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < height_width[0])
	{
		while (i < height_width[1])
		{
			write(1, &matr[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		free(matr[j]);
		i = 0;
		j++;
	}
	free(matr);
}

void	write_to_file(char *path, int fd_src, char f)
{
	int		fd;
	char	buf[1];

	fd = open(path, O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	while (read(fd_src, buf, 1) && buf[0] != f)
		write(fd, buf, 1);
	close(fd);
}
