/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_figure01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 20:00:36 by achernys          #+#    #+#             */
/*   Updated: 2018/07/16 17:10:00 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static char				figelem(int *x, int *y, t_infrmtion *inform)
{
	if (*x >= inform->piece.width)
		++*y;
	while (*y < inform->piece.height)
	{
		if (*x >= inform->piece.width)
			*x = 0;
		while (*x < inform->piece.width)
		{
			if (inform->piece.map[*y][*x] == 1)
				return (1);
			++*x;
		}
		++*y;
	}
	return (0);
}

static char				isoutcell(int x, int y, t_infrmtion *inform)
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
			if (inform->board.map[y + i][x + j] > 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static t_clctsubst		*avail_subst(int pcx, int pcy, t_infrmtion *inform,
										t_clctsubst *clctsubst)
{
	t_coords	coords;
	t_clctsubst	*newelem;

	coords.pcx = pcx;
	coords.pcy = pcy;
	coords.brdy = 0;
	while (coords.brdy < inform->board.height)
	{
		coords.brdx = 0;
		while (coords.brdx < inform->board.width)
		{
			if (inform->board.map[coords.brdy][coords.brdx] == -2 &&
				isoutcell(coords.brdx, coords.brdy, inform))
			{
				if ((newelem = try_subst(coords, inform)) != 0)
					clctsubst = addforward(clctsubst, newelem);
			}
			coords.brdx++;
		}
		coords.brdy++;
	}
	return (clctsubst);
}

static t_clctsubst		*findminsum(t_clctsubst *clctsubst, t_clctsubst *min)
{
	if (clctsubst == 0 || min == 0)
		return (0);
	if (clctsubst->next == 0)
	{
		if (clctsubst->sumval < min->sumval)
			min = clctsubst;
		return (min);
	}
	if (clctsubst->sumval < min->sumval)
		min = clctsubst;
	return (findminsum(clctsubst->next, min));
}

t_clctsubst				*substittfgr(t_infrmtion *inform, int step)
{
	int			x;
	int			y;
	t_clctsubst	*clctsubst;
	t_clctsubst	*minelem;
	t_clctsubst	*outclctsubst;

	x = 0;
	y = 0;
	clctsubst = 0;
	while (y < inform->piece.height || x < inform->piece.width)
	{
		if (figelem(&x, &y, inform))
			clctsubst = avail_subst(x, y, inform, clctsubst);
		x++;
	}
	if (inform->exception == 1 && step <= 16)
		minelem = findminy(clctsubst, clctsubst);
	else
		minelem = findminsum(clctsubst, clctsubst);
	outclctsubst = copyelem(minelem);
	if (clctsubst != 0)
		freelst(clctsubst);
	return (outclctsubst);
}
