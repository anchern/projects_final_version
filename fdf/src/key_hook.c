/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 06:21:15 by achernys          #+#    #+#             */
/*   Updated: 2019/03/13 02:35:25 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		key_hook(int key, t_data_proj **data_proj)
{
	if (key == 124 || key == 123)
		(*data_proj)->moves.shift_x += key == 124 ? SHIFT : -SHIFT;
	else if (key == 125 || key == 126)
		(*data_proj)->moves.shift_y += key == 125 ? SHIFT : -SHIFT;
	else if (key == 13 || key == 1)
		(*data_proj)->moves.rotation_x += key == 13 ? ROTATION : -ROTATION;
	else if (key == 14 || key == 12)
		(*data_proj)->moves.rotation_z += key == 14 ? ROTATION : -ROTATION;
	else if (key == 2 || key == 0)
		(*data_proj)->moves.rotation_y += key == 2 ? ROTATION : -ROTATION;
	else if (((key == 69 || key == 24) && (*data_proj)->moves.zoom <
			(short)(WIDTH / (*data_proj)->columns_num * 10)) ||
			((key == 78 || key == 27) && (*data_proj)->moves.zoom > 4))
		(*data_proj)->moves.zoom += key == 69 || key == 24 ? 3 : -3;
	else if (key == 49)
		(*data_proj)->moves = (*data_proj)->start_position;
	else if (key == 53)
		exit_x(data_proj);
	mlx_clear_window((*data_proj)->mlx_data.mlx_ptr,
			(*data_proj)->mlx_data.win_ptr);
	print_map(*data_proj);
	return (0);
}
