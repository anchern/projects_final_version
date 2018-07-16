/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 21:59:30 by achernys          #+#    #+#             */
/*   Updated: 2018/07/16 20:54:48 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../lib/mylib/ft_printf/ft_printf.h"
# include "../lib/mylib/get_next_line.h"
# include <errno.h>

typedef struct			s_field
{
	int					width;
	int					height;
	int					**map;
}						t_field;

typedef struct			s_infrmtion
{
	char				character;
	char				exception;
	t_field				board;
	t_field				piece;
}						t_infrmtion;

typedef struct			s_coords
{
	int					pcx;
	int					pcy;
	int					brdx;
	int					brdy;
}						t_coords;

typedef struct			s_clctsubst
{
	int					x;
	int					y;
	int					sumval;
	struct s_clctsubst	*next;
}						t_clctsubst;

t_infrmtion				*infominit(void);
void					informfree(t_infrmtion *inform);
void					get_character(t_infrmtion *inform, char *line);
void					get_sizepicbrd(char *str, int *width, int *height);
void					set_cellval(t_infrmtion *inform);
t_clctsubst				*substittfgr(t_infrmtion *inform, int step);
t_clctsubst				*try_subst(t_coords coords, t_infrmtion *inform);
t_clctsubst				*addforward(t_clctsubst *clctsubst,
									t_clctsubst *newelem);
t_clctsubst				*copyelem(t_clctsubst *elem);
void					freelst(t_clctsubst *lst);
void					mapfree(t_infrmtion *inform);
int						**copymap(t_infrmtion *inform);
void					delmychar(t_infrmtion *inform);
void					addmychar(t_infrmtion *inform, int **copymap);
void					freememmap(int **map, t_infrmtion *inform);
int						**get_mapfield(t_infrmtion *inform, int **map,
										int map_height);
t_clctsubst				*findminy(t_clctsubst *clctsubst, t_clctsubst *min);
void					fieldprocessing(t_infrmtion *inform, char *line);
void					pieceprocessing(t_infrmtion *inform, char *line,
										int step);
char					printresult(t_infrmtion *inform,
									t_clctsubst *substfigr);

#endif
