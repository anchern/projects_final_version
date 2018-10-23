/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:46:46 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 19:19:13 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int				vertarrlen(t_allv **vertarr)
{
	int		i;

	i = 0;
	while (vertarr[i] != 0)
		i++;
	return (i);
}

static t_allv	*minway(t_allv **vertarr)
{
	int		i;
	t_allv	*minw;

	i = 0;
	if (vertarr[0]->terminal != -1)
		minw = vertarr[0];
	else if (vertarr[1] == 0)
		return (0);
	else
		minw = vertarr[1];
	while (vertarr[i] != 0)
	{
		if (vertarr[i]->terminal != -1 && minw->value > vertarr[i]->value)
			minw = vertarr[i];
		i++;
	}
	return (minw);
}

static void		set_minway(t_allv **vertarr)
{
	int		i;
	int		arrlen;
	t_allv	*vertex;
	t_allv	*prevvert;

	i = 0;
	arrlen = vertarrlen(vertarr);
	while (i < arrlen)
	{
		vertex = vertarr[i];
		prevvert = vertex;
		while (vertex->value != 0)
		{
			if ((vertex->nextway = minway(vertex->adjarr)) == 0)
				break ;
			if (vertex->nextway->num_v == prevvert->num_v)
			{
				vertex->nextway = 0;
				break ;
			}
			prevvert = vertex;
			vertex = vertex->nextway;
		}
		i++;
	}
}

t_allv			**sortvert(t_allv **vertarr)
{
	int		i;
	int		j;
	int		arrlen;
	t_allv	*tmp;

	i = 0;
	arrlen = vertarrlen(vertarr);
	while (i < arrlen)
	{
		j = arrlen - 1;
		while (j > i)
		{
			if (vertarr[i]->value > vertarr[j]->value)
			{
				tmp = vertarr[i];
				vertarr[i] = vertarr[j];
				vertarr[j] = tmp;
			}
			j--;
		}
		i++;
	}
	set_minway(vertarr);
	return (vertarr);
}
