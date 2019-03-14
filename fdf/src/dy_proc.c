/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dy_proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 01:29:52 by achernys          #+#    #+#             */
/*   Updated: 2019/03/13 02:36:33 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_dy_cycle(t_vector vector, double interx, t_mlx_data mlx_data,
					double grad)
{
	int y;
	int color_koef;
	int color;

	y = (int)round(vector.p_start.y) + 1;
	while (y < vector.p_end.y)
	{
		color_koef = (int)(255 - fpart(interx) * 255);
		color = (unsigned)color_koef * 65536 + (unsigned)(color_koef) *
												256 + (unsigned)color_koef;
		if ((int)interx <= WIDTH && (int)interx >= 0 && y >= 0 && y <= HEIGHT)
			mlx_pixel_put(mlx_data.mlx_ptr, mlx_data.win_ptr, (int)interx, y,
				color);
		color_koef = (int)(fpart(interx) * 255);
		color = (unsigned)color_koef * 65536 + (unsigned)(color_koef) *
												256 + (unsigned)color_koef;
		if ((int)interx + 1 <= WIDTH && (int)interx + 1 >= 0 && y >= 0 &&
				y <= HEIGHT)
			mlx_pixel_put(mlx_data.mlx_ptr, mlx_data.win_ptr, (int)interx + 1,
				y, color);
		interx += grad;
		y++;
	}
}

void	ft_dy(t_vector vector, double dx, double dy, t_mlx_data mlx_data)
{
	double	grad;
	double	interx;

	if (vector.p_end.y < vector.p_start.y)
		switch_start_end(&vector);
	grad = dx / dy;
	if (vector.p_end.x < vector.p_start.x)
		grad = -grad;
	interx = vector.p_start.x + grad;
	mlx_pixel_put(mlx_data.mlx_ptr, mlx_data.win_ptr,
			(int)round(vector.p_start.x),
			(int)round(vector.p_start.y), 0xFFFFFF);
	ft_dy_cycle(vector, interx, mlx_data, grad);
	mlx_pixel_put(mlx_data.mlx_ptr, mlx_data.win_ptr,
			(int)round(vector.p_end.x), (int)round(vector.p_end.y), 0xFFFFFF);
}
