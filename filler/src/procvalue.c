/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procvalue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:05:58 by achernys          #+#    #+#             */
/*   Updated: 2018/07/16 15:08:32 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static char	istchfreepnt(int x, int y, t_infrmtion *inform)
{
	int		i;
	int		j;

	i = -1;
	while (i <= 1)
	{
		if (y + i >= inform->board.height || y + i < 0 ? ++i : 0)
			continue ;
		j = -1;
		while (j <= 1)
		{
			if (x + j >= inform->board.width || x + j < 0)
			{
				j++;
				continue ;
			}
			if (inform->board.map[y + i][x + j] == -1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	set_val(int x, int y, int curmaxval, t_infrmtion *inform)
{
	int		i;
	int		j;

	i = -1;
	while (i <= 1)
	{
		if (y + i >= inform->board.height || y + i < 0)
		{
			i++;
			continue ;
		}
		j = -1;
		while (j <= 1)
		{
			if ((i == 0 && j == 0) || x + j >= inform->board.width || x + j < 0)
			{
				j++;
				continue;
			}
			if (inform->board.map[y + i][x + j] == -1)
				inform->board.map[y + i][x + j] = curmaxval + 1;
			j++;
		}
		i++;
	}
}

static char	surround(t_infrmtion *inform, int curmaxval)
{
	int		x;
	int		y;
	char	flag;

	y = 0;
	flag = 0;
	while (y < inform->board.height)
	{
		x = 0;
		while (x < inform->board.width)
		{
			if (inform->board.map[y][x] == curmaxval &&
					istchfreepnt(x, y, inform))
			{
				set_val(x, y, curmaxval, inform);
				flag = 1;
			}
			x++;
		}
		y++;
	}
	return (flag);
}

void		set_cellval(t_infrmtion *inform)
{
	int		curmaxval;
	int		**map_witoutchar;

	map_witoutchar = copymap(inform);
	delmychar(inform);
	curmaxval = 0;
	while (surround(inform, curmaxval))
	{
		curmaxval++;
	}
	addmychar(inform, map_witoutchar);
	freememmap(map_witoutchar, inform);
}
