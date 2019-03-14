/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 06:28:04 by achernys          #+#    #+#             */
/*   Updated: 2019/02/28 06:45:42 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_rows	*new_rows_elem(double *new_row)
{
	t_rows	*rows;

	rows = (t_rows *)ft_memalloc(sizeof(rows));
	rows->row = new_row;
	rows->next = 0;
	return (rows);
}

void	push_row_back(t_rows **rows, t_rows *new_rows_elem)
{
	if (*rows == 0)
	{
		*rows = new_rows_elem;
		return ;
	}
	if ((*rows)->next == 0)
	{
		(*rows)->next = new_rows_elem;
		return ;
	}
	push_row_back(&(*rows)->next, new_rows_elem);
}

size_t	get_row_len(char *line)
{
	int		i;
	size_t	row_len;

	row_len = 0;
	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '-' || line[i] == '+')
			i++;
		if (ft_isdigit(line[i]))
			row_len++;
		else
			read_error();
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (line[i] == 0)
			break ;
		while (line[i] && line[i] == ' ')
			i++;
	}
	return (row_len);
}

double	*get_row(char *line)
{
	double	*row;
	int		i;
	int		j;

	i = 0;
	j = 0;
	row = (double *)ft_memalloc(get_row_len(line) * sizeof(double));
	while (line[i] != 0)
	{
		row[j] = (double)ft_atoi(&line[i]);
		j++;
		if (line[i] == '-' || line[i] == '+')
			i++;
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (line[i] == 0)
			break ;
		while (line[i] == ' ')
			i++;
	}
	return (row);
}

void	free_rows(t_rows *rows)
{
	if (rows == 0)
		return ;
	free_rows(rows->next);
	free(rows);
}
