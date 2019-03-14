/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 01:09:02 by achernys          #+#    #+#             */
/*   Updated: 2019/03/13 01:34:05 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double		fpart(double x)
{
	return (x - (int)x);
}

void		switch_start_end(t_vector *vector)
{
	vector->p_end.x += vector->p_start.x;
	vector->p_start.x = vector->p_end.x - vector->p_start.x;
	vector->p_end.x -= vector->p_start.x;
	vector->p_end.y += vector->p_start.y;
	vector->p_start.y = vector->p_end.y - vector->p_start.y;
	vector->p_end.y -= vector->p_start.y;
}

void		print_line(t_vector vector, t_mlx_data mlx_data)
{
	double dx;
	double dy;

	dy = (vector.p_end.y > vector.p_start.y) ? (vector.p_end.y -
			vector.p_start.y) : (vector.p_start.y - vector.p_end.y);
	dx = (vector.p_end.x > vector.p_start.x) ? (vector.p_end.x -
			vector.p_start.x) : (vector.p_start.x - vector.p_end.x);
	if (dx == 0 || dy == 0)
	{
		draw_line(vector, mlx_data.mlx_ptr, mlx_data.win_ptr, 0xFFFFFF);
		return ;
	}
	if (dy < dx)
		ft_dx(vector, dx, dy, mlx_data);
	else
		ft_dy(vector, dx, dy, mlx_data);
}

void		draw_line(t_vector vector, void *mlx_ptr, void *win_ptr,
					unsigned color)
{
	while (vector.p_start.x < vector.p_end.x ||
			vector.p_start.y < vector.p_end.y)
	{
		if (vector.p_start.x > vector.p_end.x)
			vector.p_start.x--;
		else if (vector.p_start.x < vector.p_end.x)
			vector.p_start.x++;
		if (vector.p_start.y > vector.p_end.y)
			vector.p_start.y--;
		else if (vector.p_start.y < vector.p_end.y)
			vector.p_start.y++;
		mlx_pixel_put(mlx_ptr, win_ptr, (int)round(vector.p_start.x),
				(int)round(vector.p_start.y), color);
	}
}
