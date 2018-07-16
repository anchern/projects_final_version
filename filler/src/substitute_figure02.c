/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_figure02.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:23:49 by achernys          #+#    #+#             */
/*   Updated: 2018/07/16 13:40:49 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static t_clctsubst	*initelem(int x, int y, int sumval)
{
	t_clctsubst	*clctsubst;

	clctsubst = ft_memalloc(sizeof(t_clctsubst));
	clctsubst->x = x;
	clctsubst->y = y;
	clctsubst->sumval = sumval;
	clctsubst->next = 0;
	return (clctsubst);
}

static inline char	overabroad(t_coords rcoords, t_infrmtion *inform)
{
	return (rcoords.brdy > inform->board.height ||
			rcoords.brdx > inform->board.width ||
			rcoords.brdx < 0 || rcoords.brdy < 0);
}

static char			iscompatibility(t_coords rcoords, t_coords coords,
									t_infrmtion *inform)
{
	if (coords.brdy >= inform->board.height || coords.brdx >=
															inform->board.width)
	{
		if (inform->piece.map[coords.pcy][coords.pcx] == 1)
			return (0);
		else
			return (2);
	}
	if ((overabroad(coords, inform) ||
		inform->board.map[coords.brdy][coords.brdx] <= 0) &&
		inform->piece.map[coords.pcy][coords.pcx] == 1)
	{
		if (rcoords.pcx == coords.pcx && rcoords.pcy == coords.pcy &&
			rcoords.brdx == coords.brdx && rcoords.brdy == coords.brdy)
			return (2);
		else
			return (0);
	}
	else if (inform->piece.map[coords.pcy][coords.pcx] == 1)
		return (1);
	return (2);
}

t_clctsubst			*try_subst(t_coords coords, t_infrmtion *inform)
{
	t_coords	rcoords;
	int			sumv;
	char		tmp;

	rcoords.brdy = coords.brdy - coords.pcy;
	rcoords.pcy = 0;
	sumv = 0;
	while (rcoords.pcy < inform->piece.height)
	{
		rcoords.pcx = 0;
		rcoords.brdx = coords.brdx - coords.pcx;
		while (rcoords.pcx < inform->piece.width)
		{
			if ((tmp = iscompatibility(coords, rcoords, inform)) == 0)
				return (0);
			else if (tmp == 1)
				sumv += inform->board.map[rcoords.brdy][rcoords.brdx];
			rcoords.brdx++;
			rcoords.pcx++;
		}
		rcoords.brdy++;
		rcoords.pcy++;
	}
	return (initelem(coords.brdx - coords.pcx, coords.brdy - coords.pcy, sumv));
}
