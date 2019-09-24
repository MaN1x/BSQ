/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_to_head.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:48:13 by npetrell          #+#    #+#             */
/*   Updated: 2019/08/22 06:25:38 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_func.h"
#define PARAMS "tmp/params.txt"

int			count_param(void)
{
	int		count;
	int		fd;
	char	buff[1];

	count = 0;
	fd = open(PARAMS, O_RDONLY);
	while (read(fd, buff, 1))
		count++;
	close(fd);
	return (count);
}

int			check_valid_head(void)
{
	int		fd;
	int		count;
	char	*h_char;

	count = count_param();
	h_char = (char*)malloc(count * sizeof(char));
	fd = open(PARAMS, O_RDONLY);
	read(fd, h_char, count);
	close(fd);
	if (valid_head_symbol() == 0)
		return (0);
	free(h_char);
	return (1);
}

int			valid_head_symbol(void)
{
	int		i;
	int		j;
	int		fd;
	int		count;
	char	*h_char;

	i = 0;
	j = 0;
	count = count_param();
	h_char = (char*)malloc(count * sizeof(char));
	if (h_char[0] <= '0' && h_char[0] > '9')
		return (0);
	fd = open(PARAMS, O_RDONLY);
	read(fd, h_char, count);
	close(fd);
	while (h_char[i] >= '0' && h_char[i] <= '9')
		i++;
	while (i++ < count)
		j++;
	free(h_char);
	if (j != 3)
		return (0);
	return (1);
}
