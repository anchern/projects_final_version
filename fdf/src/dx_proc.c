/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dx_proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 01:30:49 by achernys          #+#    #+#             */
/*   Updated: 2019/03/13 02:37:13 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_dx_cycle(t_vector vector, double intery, t_mlx_data mlx_data,
					double grad)
{
	int x;
	int color_koef;
	int color;

	x = (int)round(vector.p_start.x) + 1;
	while (x < vector.p_end.x)
	{
		color_koef = (int)(255 - fpart(intery) * 255);
		color = (unsigned)color_koef * 65536 + (unsigned)(color_koef) * 256 +
				(unsigned)color_koef;
		if (x <= WIDTH && x >= 0 && (int)intery > 0 && (int)intery < HEIGHT)
			mlx_pixel_put(mlx_data.mlx_ptr, mlx_data.win_ptr, x, (int)intery,
					color);
		color_koef = (int)(fpart(intery) * 255);
		color = (unsigned)color_koef * 65536 + (unsigned)(color_koef) * 256 +
				(unsigned)color_koef;
		if (x <= WIDTH && x >= 0 && (int)intery + 1 > 0 &&
				(int)intery + 1 < HEIGHT)
			mlx_pixel_put(mlx_data.mlx_ptr, mlx_data.win_ptr, x,
				(int)intery + 1, color);
		intery += grad;
		x++;
	}
}

void	ft_dx(t_vector vector, double dx, double dy, t_mlx_data mlx_data)
{
	double		grad;
	double		intery;

	if (vector.p_end.x < vector.p_start.x)
		switch_start_end(&vector);
	grad = dy / dx;
	if (vector.p_end.y < vector.p_start.y)
		grad = -grad;
	intery = vector.p_start.y + grad;
	mlx_pixel_put(mlx_data.mlx_ptr, mlx_data.win_ptr,
		(int)round(vector.p_start.x), (int)round(vector.p_start.y), 0xFFFFFF);
	ft_dx_cycle(vector, intery, mlx_data, grad);
	mlx_pixel_put(mlx_data.mlx_ptr, mlx_data.win_ptr,
		(int)round(vector.p_end.x), (int)round(vector.p_end.y), 0xFFFFFF);
}
