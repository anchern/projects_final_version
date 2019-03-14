/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 06:07:50 by achernys          #+#    #+#             */
/*   Updated: 2019/03/13 02:38:15 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		exit_x(void)
{
	exit(0);
}

void	control_information(void)
{
	ft_printf("{green}Control:{eoc}\n");
	ft_printf("{green}Q/E{eoc} - rotation Z\n");
	ft_printf("{green}A/D{eoc} - rotation Y\n");
	ft_printf("{green}W/S{eoc} - rotation X\n");
	ft_printf("{green}UP/DOWN/LEFT/RIGHT arrow{eoc} - shift\n");
	ft_printf("{green}NUM_+/={eoc} - increase\n");
	ft_printf("{green}NUM_-/-{eoc} - decrease\n");
	ft_printf("{green}ESC{eoc} - exit\n");
}

void	read_error(void)
{
	ft_printf("{red}Can't read file.{eoc}\n");
	ft_printf("{green}Usage:{eoc} ./fdf fdfmap.fdf\n");
	exit(READ_ERR);
}

size_t	get_max_arr_val(double **map, size_t rows, size_t columns)
{
	double	max;
	size_t	i;
	size_t	j;

	max = map[0][0];
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (max < map[i][j])
				max = map[i][j];
			j++;
		}
		i++;
	}
	return ((size_t)max);
}

int		main(int argc, char **argv)
{
	t_data_proj *data_proj;
	size_t		max_arr_val;

	data_proj = init_data_struct(argv);
	if (data_proj->columns_num == 1 || data_proj->rows_num == 1)
		read_error();
	max_arr_val = get_max_arr_val(data_proj->map, data_proj->rows_num,
			data_proj->columns_num);
	if (max_arr_val > data_proj->columns_num || max_arr_val >
			data_proj->rows_num)
		data_proj->moves.zoom /= 4;
	data_proj->start_position = data_proj->moves;
	control_information();
	print_map(data_proj);
	mlx_key_hook(data_proj->mlx_data.win_ptr, key_hook,
				&data_proj);
	mlx_hook(data_proj->mlx_data.win_ptr, 17, 1L << 17, exit_x,
			&data_proj);
	mlx_loop(data_proj->mlx_data.mlx_ptr);
	argc--;
	return (0);
}
