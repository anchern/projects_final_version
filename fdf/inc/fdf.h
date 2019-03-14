/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:03:28 by achernys          #+#    #+#             */
/*   Updated: 2019/03/14 12:03:31 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/mylib/ft_printf/ft_printf.h"
# include "../lib/mylib/get_next_line.h"
# include "../lib/minilibx_macos/mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

# define READ_ERR 70

# define SHIFT 20
# define ROTATION 0.1

# define WIDTH 1280
# define HEIGHT 720

typedef struct		s_rows
{
	double			*row;
	struct s_rows	*next;
}					t_rows;

typedef struct		s_point
{
	double				x;
	double				y;
	double				z;
}					t_point;

typedef struct		s_moves
{
	short			zoom;
	short			shift_x;
	short			shift_y;
	double			rotation_z;
	double			rotation_x;
	double			rotation_y;
}					t_moves;

typedef struct		s_vector
{
	t_point			p_start;
	t_point			p_end;
}					t_vector;

typedef struct		s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;

}					t_mlx_data;

typedef struct		s_data_project
{
	double			**map;
	size_t			columns_num;
	size_t			rows_num;
	t_mlx_data		mlx_data;
	t_moves			moves;
	t_moves			start_position;
}					t_data_proj;

void				print_line(t_vector vector, t_mlx_data mlx_data);
double				**get_map(int fd, t_data_proj *data_project);
void				draw_line(t_vector vector, void	*mlx_ptr, void	*win_ptr,
								unsigned color);
void				rotation(t_vector *vector, t_moves moves);
t_data_proj			*init_data_struct(char **argv);
int					key_hook(int key, t_data_proj **data_proj);
void				print_map(t_data_proj *data_proj);
void				move(t_vector *vector, int move_x, int move_y);
void				zoom(t_vector *vector, int zoom);
t_rows				*new_rows_elem(double *new_row);
double				*get_row(char *line);
size_t				get_row_len(char *line);
void				push_row_back(t_rows **rows, t_rows *new_rows_elem);
void				free_rows(t_rows *rows);
int					exit_x();
size_t				get_max_arr_val(double **map, size_t rows, size_t columns);
double				fpart(double x);
void				switch_start_end(t_vector *vector);
void				ft_dx(t_vector vector, double dx, double dy,
								t_mlx_data mlx_data);
void				ft_dy(t_vector vector, double dx, double dy,
								t_mlx_data mlx_data);
void				read_error();

#endif
