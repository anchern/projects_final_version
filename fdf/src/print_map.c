/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 06:23:03 by achernys          #+#    #+#             */
/*   Updated: 2019/03/13 01:44:36 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	prep_print_right_line(size_t x, size_t y, t_data_proj *data_proj,
								double k)
{
	t_vector	vector;

	vector.p_start.x = x;
	vector.p_end.x = x + 1;
	vector.p_start.y = y;
	vector.p_end.y = y;
	vector.p_start.z = data_proj->map[y][x];
	vector.p_end.z = data_proj->map[y][x + 1];
	zoom(&vector, data_proj->moves.zoom);
	move(&vector, -(int)((data_proj->columns_num - 1) * data_proj->moves.zoom /
	2), -(int)((data_proj->rows_num - 1) * data_proj->moves.zoom / 2));
	rotation(&vector, data_proj->moves);
	if (vector.p_start.z - k / 40 > -k || vector.p_end.z - k / 40 > -k)
		return ;
	vector.p_start.x = k * vector.p_start.x / (vector.p_start.z + k);
	vector.p_start.y = k * vector.p_start.y / (vector.p_start.z + k);
	vector.p_end.x = k * vector.p_end.x / (vector.p_end.z + k);
	vector.p_end.y = k * vector.p_end.y / (vector.p_end.z + k);
	move(&vector, data_proj->moves.shift_x, data_proj->moves.shift_y);
	if ((vector.p_end.x > WIDTH && vector.p_start.x > WIDTH) ||
	(vector.p_end.x < 0 && vector.p_start.x < 0) ||
	(vector.p_end.y > HEIGHT && vector.p_start.y > HEIGHT) ||
	(vector.p_end.y < 0 && vector.p_start.y < 0))
		return ;
	print_line(vector, data_proj->mlx_data);
}

void	prep_print_down_line(size_t x, size_t y, t_data_proj *data_proj,
		double k)
{
	t_vector	vector;

	vector.p_start.x = x;
	vector.p_end.x = x;
	vector.p_start.y = y;
	vector.p_end.y = y + 1;
	vector.p_start.z = data_proj->map[y][x];
	vector.p_end.z = data_proj->map[y + 1][x];
	zoom(&vector, data_proj->moves.zoom);
	move(&vector, -(int)((data_proj->columns_num - 1) * data_proj->moves.zoom /
	2), -(int)((data_proj->rows_num - 1) * data_proj->moves.zoom / 2));
	rotation(&vector, data_proj->moves);
	if (vector.p_start.z - k / 40 > -k || vector.p_end.z - k / 40 > -k)
		return ;
	vector.p_start.x = k * vector.p_start.x / (vector.p_start.z + k);
	vector.p_start.y = k * vector.p_start.y / (vector.p_start.z + k);
	vector.p_end.x = k * vector.p_end.x / (vector.p_end.z + k);
	vector.p_end.y = k * vector.p_end.y / (vector.p_end.z + k);
	move(&vector, data_proj->moves.shift_x, data_proj->moves.shift_y);
	if ((vector.p_end.x > WIDTH && vector.p_start.x > WIDTH) ||
		(vector.p_end.x < 0 && vector.p_start.x < 0) ||
		(vector.p_end.y > HEIGHT && vector.p_start.y > HEIGHT) ||
		(vector.p_end.y < 0 && vector.p_start.y < 0))
		return ;
	print_line(vector, data_proj->mlx_data);
}

void	print_map(t_data_proj *data_proj)
{
	size_t		x;
	size_t		y;
	double		k;

	y = 0;
	k = -400;
	while (y < data_proj->rows_num - 1)
	{
		x = 0;
		while (x < data_proj->columns_num - 1)
		{
			prep_print_right_line(x, y, data_proj, k);
			prep_print_down_line(x, y, data_proj, k);
			x++;
		}
		prep_print_down_line(x, y, data_proj, k);
		y++;
	}
	x = 0;
	while (x < data_proj->columns_num - 1)
	{
		prep_print_right_line(x, y, data_proj, k);
		x++;
	}
}
