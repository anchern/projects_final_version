/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:02:09 by achernys          #+#    #+#             */
/*   Updated: 2018/10/16 20:51:39 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lem_in.h"

static void	add_back(t_allv **allv, t_allv *newelem, int iter)
{
	if (*allv == 0)
	{
		newelem->num_v = 0;
		*allv = newelem;
		return ;
	}
	if ((*allv)->next == 0)
	{
		newelem->num_v = iter + 1;
		(*allv)->next = newelem;
		return ;
	}
	add_back(&(*allv)->next, newelem, iter + 1);
}

static void	isuniquevert(t_allv *allv, t_allv *newelem)
{
	if (allv == 0)
		return ;
	if ((allv->x == newelem->x && allv->y == newelem->y) ||
			ft_strcmp(allv->name_v, newelem->name_v) == 0)
		repeatcoorderr();
	return (isuniquevert(allv->next, newelem));
}

static void	set_newelem(char *line, t_term *term, t_allv **newelem)
{
	size_t	i;

	i = 0;
	while (line[i] != ' ')
		i++;
	(*newelem)->name_v = ft_strnew(i);
	ft_memcpy((void *)(*newelem)->name_v, (void *)line, i);
	i++;
	(*newelem)->x = ft_atoi(&line[i]);
	if (line[i] == '-')
		i++;
	while (line[i] != ' ' && line[i] != '-')
		i++;
	(*newelem)->y = ft_atoi(&line[i]);
	if (term->start == 1)
	{
		(*newelem)->terminal = 1;
		term->start = 2;
	}
	if (term->end == 1)
	{
		(*newelem)->terminal = -1;
		term->end = 2;
	}
}

void		addvertex(char *line, t_allv **allv, t_term *term)
{
	t_allv	*newelem;

	if (!(newelem = (t_allv *)ft_memalloc(sizeof(t_allv))))
	{
		ft_printf("{red}Memory shortage.{eoc}\n");
		exit(MEM_OUT_ERR);
	}
	newelem->adjv = 0;
	newelem->value = -1;
	newelem->adjarr = 0;
	newelem->antnum = 0;
	newelem->nextway = 0;
	newelem->next = 0;
	set_newelem(line, term, &newelem);
	isuniquevert(*allv, newelem);
	add_back(allv, newelem, 0);
}
