/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:01:29 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 19:09:07 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lem_in.h"

static char	isuniqvert(t_allv *way, t_allv *vert)
{
	if (way->num_v == vert->num_v)
		return (0);
	if (way->nextway == 0)
		return (1);
	return (isuniqvert(way->nextway, vert));
}

static char	uniqway(t_allv *way1, t_allv *way2)
{
	if (way2->nextway == 0)
	{
		if (way2->terminal == 1)
			return (1);
		else
			return (0);
	}
	if (!isuniqvert(way1, way2))
		return (0);
	return (uniqway(way1, way2->nextway));
}

static char	isdeadlock(t_allv *way)
{
	if (way->nextway == 0)
	{
		if (way->terminal == 1)
			return (0);
		else
			return (1);
	}
	return (isdeadlock(way->nextway));
}

static int	deldeadlock(t_allv **adjarr, int arrsize)
{
	int		i;

	i = 0;
	while (i < arrsize)
	{
		if (isdeadlock(adjarr[i]))
			adjarr[i] = 0;
		i++;
	}
	i = 0;
	while (adjarr[i] == 0 && i < arrsize)
		i++;
	if (i == arrsize)
		noposswayerr();
	return (i);
}

void		uncsrwaysdel(t_allv **adjarr, int arrsize)
{
	int		i;
	int		firstway;

	firstway = deldeadlock(adjarr, arrsize);
	arrsize--;
	while (arrsize >= 0)
	{
		i = firstway;
		while (i < arrsize)
		{
			if (!uniqway(adjarr[i], adjarr[arrsize]))
			{
				adjarr[arrsize] = 0;
				break ;
			}
			i++;
		}
		arrsize--;
	}
}
