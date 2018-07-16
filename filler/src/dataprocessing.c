/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataprocessing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:48:43 by achernys          #+#    #+#             */
/*   Updated: 2018/07/16 20:49:06 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static void	isexception(t_infrmtion *inform)
{
	int		y;
	int		x;
	int		coords[4];

	if (inform->board.height > 25 && inform->board.width > 25)
		return ;
	y = 0;
	while (y < inform->board.height)
	{
		x = 0;
		while (x < inform->board.width)
		{
			if (inform->board.map[y][x] == 0 || inform->board.map[y][x] == -2)
			{
				coords[inform->board.map[y][x] == 0 ? 0 : 2] = y;
				coords[inform->board.map[y][x] == 0 ? 1 : 3] = x;
			}
			x++;
		}
		y++;
	}
	if (coords[2] > coords[0] && coords[3] > coords[1])
		inform->exception = 1;
}

void		fieldprocessing(t_infrmtion *inform, char *line)
{
	while (ft_strstr(line, "Plateau") == 0)
	{
		ft_memdel((void **)&line);
		get_next_line(0, &line);
	}
	get_sizepicbrd(line, &(inform->board.width), &(inform->board.height));
	ft_memdel((void **)&line);
	get_next_line(0, &line);
	ft_memdel((void **)&line);
	inform->board.map = get_mapfield(inform, inform->board.map,
										inform->board.height);
}

void		pieceprocessing(t_infrmtion *inform, char *line, int step)
{
	get_next_line(0, &line);
	get_sizepicbrd(line, &(inform->piece.width),
					&(inform->piece.height));
	ft_memdel((void **)&line);
	inform->piece.map = get_mapfield(inform, inform->piece.map,
										inform->piece.height);
	if (step == 1 && inform->exception == 0)
		isexception(inform);
}
