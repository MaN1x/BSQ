/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:42:58 by mjoss             #+#    #+#             */
/*   Updated: 2019/08/22 03:53:07 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FUNC_H
# define __FT_FUNC_H

int		ft_atoi(char *str);
int		check(int *coords, int size, char **matr, char *contain);
void	solve(char **matr, int *height_width, char *contain);
int		check_size(int size, int *height_width, char **matr, char *contain);
void	fill(int *coords, int size, char **matr, char *contain);
char	**from_file_to_matr(char *path, char **matr, int *height_width);
void	print_matr(int *height_width, char **matr);
void	write_to_file(char *path, int fd_src, char f);
int		check_valid_head(void);
int		valid_head_symbol(void);
int		check_map_valid(char *contain, int *height_width);
int		ft_check_height(void);
int		ft_size(void);
int		map_valid_symbol(char *contain);
int		map_valid_line(int *height_width);
int		count_param(void);

#endif
