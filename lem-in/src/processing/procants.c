/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:50:05 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 19:28:57 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lem_in.h"

static int	get_numways(t_allv **waysarr)
{
	int		i;

	i = 0;
	while (waysarr[i] != 0)
		i++;
	return (i);
}

static int	get_nextway(t_allv **arr, int wcur, int arrsize)
{
	while (wcur < arrsize && arr[wcur] == 0)
		wcur++;
	return (wcur);
}

static void	move(t_allv *way, unsigned long *numant, int **antsroom)
{
	if (way->nextway->terminal == 1)
	{
		if (numant == 0)
			way->antnum = 0;
		if (numant == 0)
			return ;
		if (way->nextway->antnum == 0)
		{
			way->antnum = 0;
			*numant = 0;
			return ;
		}
		else
		{
			way->antnum = *numant;
			if (*numant != 0)
				(*antsroom)[*numant - 1] = way->num_v;
			++(*numant) && --way->nextway->antnum;
			return ;
		}
	}
	way->antnum = way->nextway->antnum;
	if (way->antnum != 0)
		(*antsroom)[way->antnum - 1] = way->num_v;
	move(way->nextway, numant, antsroom);
}

static void	moveants(t_allv *allv, int numways, int **antsroom,
						unsigned long *ant)
{
	int		wcur;
	int		startway;
	t_allv	*endv;
	t_allv	*startv;

	endv = findbyterm(allv, -1);
	startv = findbyterm(allv, 1);
	startway = get_nextway(endv->adjarr, 0, numways);
	wcur = startway;
	while (wcur < numways)
	{
		if (endv->adjarr[wcur]->terminal == 1)
		{
			if (get_ant(endv, wcur, antsroom, ant))
				break ;
			wcur = get_nextway(endv->adjarr, wcur + 1, numways);
			continue ;
		}
		if (endv->adjarr[wcur]->antnum != 0)
			(*antsroom)[endv->adjarr[wcur]->antnum - 1] = endv->num_v;
		move(endv->adjarr[wcur], wcur == startway ||
			endv->adjarr[wcur]->value - endv->adjarr[startway]->value <
					(int)startv->antnum ? ant : 0, antsroom);
		wcur = get_nextway(endv->adjarr, wcur + 1, numways);
	}
}

void		ants_gogogo(t_allv *endv, unsigned long ants, t_allv *allv)
{
	int				*antsroom;
	int				numways;
	char			complete;
	unsigned long	antnum;

	numways = get_numways(endv->adjarr);
	uncsrwaysdel(endv->adjarr, numways);
	antsroom = (int *)ft_memalloc(sizeof(int) * ants + 1);
	arrnullify(&antsroom, ants);
	complete = 1;
	antnum = 1;
	while (complete)
	{
		moveants(allv, numways, &antsroom, &antnum);
		printants(endv, &antsroom, allv);
		ft_printf("\n");
		complete = !iscomplete(antsroom);
	}
	free(antsroom);
}
