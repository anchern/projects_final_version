/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 03:47:06 by achernys          #+#    #+#             */
/*   Updated: 2019/02/28 08:46:57 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static size_t	get_rows_num(t_rows *rows, size_t counter)
{
	if (rows == 0)
		return (counter);
	return (get_rows_num(rows->next, counter + 1));
}

void			write_rows_in_map(double **map, t_rows *rows)
{
	int		i;

	i = 0;
	while (rows != 0)
	{
		map[i] = rows->row;
		i++;
		rows = rows->next;
	}
}

double			**get_map(int fd, t_data_proj *data_project)
{
	char	*line;
	double	**map;
	t_rows	*rows;

	rows = 0;
	if (get_next_line(fd, &line) <= 0)
		read_error();
	data_project->columns_num = get_row_len(line);
	push_row_back(&rows, new_rows_elem(get_row(line)));
	free(line);
	while (get_next_line(fd, &line))
	{
		if (get_row_len(line) != data_project->columns_num)
			read_error();
		push_row_back(&rows, new_rows_elem(get_row(line)));
		ft_memdel((void **)&line);
	}
	data_project->rows_num = get_rows_num(rows, 0);
	map = (double **)ft_memalloc(sizeof(double *) * data_project->rows_num);
	write_rows_in_map(map, rows);
	free_rows(rows);
	return (map);
}
