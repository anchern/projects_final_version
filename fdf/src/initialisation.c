/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 03:49:01 by achernys          #+#    #+#             */
/*   Updated: 2019/03/13 01:19:04 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_data_proj	*init_data_struct(char **argv)
{
	int			fd;
	t_data_proj	*data_proj;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		read_error();
	data_proj = (t_data_proj *)ft_memalloc(sizeof(t_data_proj));
	data_proj->mlx_data.mlx_ptr = mlx_init();
	data_proj->mlx_data.win_ptr = mlx_new_window(data_proj->mlx_data.mlx_ptr,
			WIDTH, HEIGHT, "MyApp");
	data_proj->map = get_map(fd, data_proj);
	data_proj->moves.zoom = (short)round(((double)WIDTH /
		data_proj->columns_num + (double)HEIGHT / data_proj->columns_num) / 3);
	data_proj->moves.rotation_x = 0.4;
	data_proj->moves.rotation_y = 0;
	data_proj->moves.rotation_z = 0;
	data_proj->moves.shift_x = WIDTH / 2;
	data_proj->moves.shift_y = HEIGHT / 2;
	return (data_proj);
}
