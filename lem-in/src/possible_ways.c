/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:56:51 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 20:42:31 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void		set_adjarrv(t_allv *allv, int maxadjvert)
{
	t_allv	**adjarr;
	int		i;
	t_allv	*curvert;
	t_adjv	*adjv;

	curvert = allv;
	while (curvert != 0)
	{
		i = 0;
		adjv = curvert->adjv;
		adjarr = (t_allv **)ft_memalloc(sizeof(t_allv *) * maxadjvert + 1);
		adjarr[maxadjvert] = 0;
		while (i < maxadjvert)
		{
			adjarr[i] = adjv == 0 ? 0 : findvbyname(adjv->name_v, allv);
			adjv = adjv == 0 ? 0 : adjv->next;
			i++;
		}
		freeadjv(curvert->adjv);
		curvert->adjarr = adjarr;
		curvert = curvert->next;
	}
}

t_allv			*possways(t_allv *allv, int maxadjvert, unsigned long ants)
{
	t_allv	*startv;
	t_allv	*endv;

	set_adjarrv(allv, maxadjvert);
	startv = findbyterm(allv, 1);
	startv->value = 0;
	startv->antnum = ants;
	dfs(startv);
	endv = findbyterm(allv, -1);
	endv->adjarr = sortvert(endv->adjarr);
	return (endv);
}
