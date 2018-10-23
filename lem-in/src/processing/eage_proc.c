/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eage_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 12:38:12 by achernys          #+#    #+#             */
/*   Updated: 2018/08/04 12:38:47 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lem_in.h"

void		getvnames(char *line, char **vname, char **adjvname)
{
	size_t	i;

	i = 0;
	while (line[i] != '-')
		i++;
	*vname = ft_strnew(i);
	ft_memcpy((void *)*vname, (void *)line, i);
	i++;
	*adjvname = ft_strnew(ft_strlen(&line[i]));
	ft_strcpy(*adjvname, &line[i]);
}

t_allv		*findvbyname(char *name, t_allv *allv)
{
	if (allv == 0)
		return (0);
	if (ft_strcmp(name, allv->name_v) == 0)
		return (allv);
	return (findvbyname(name, allv->next));
}

static char	isexistingeage(t_adjv *adjv, t_allv *adjvertex)
{
	if (adjv == 0 || adjvertex->adjv == 0)
		return (0);
	if (adjv->num_v == adjvertex->num_v)
		return (1);
	return (isexistingeage(adjv->next, adjvertex));
}

void		newadjv(t_allv **vertex, t_allv *adjvertex)
{
	t_adjv	*curadjv;
	t_adjv	*adjv;

	if (isexistingeage((*vertex)->adjv, adjvertex))
		return ;
	adjv = (t_adjv *)ft_memalloc(sizeof(t_adjv));
	adjv->name_v = ft_strdup(adjvertex->name_v);
	adjv->num_v = adjvertex->num_v;
	adjv->next = 0;
	if ((*vertex)->adjv == 0)
		(*vertex)->adjv = adjv;
	else
	{
		curadjv = (*vertex)->adjv;
		while (curadjv->next != 0)
			curadjv = curadjv->next;
		curadjv->next = adjv;
	}
}

char		setadjv(char *line, t_allv **allv)
{
	char	*vname;
	char	*adjvname;
	t_allv	*curvertex;
	t_allv	*adjvertex;

	if (allv == 0 || *allv == 0)
		noroomerr();
	getvnames(line, &vname, &adjvname);
	if ((curvertex = findvbyname(vname, *allv)) == 0)
		return (0);
	if ((adjvertex = findvbyname(adjvname, *allv)) == 0)
		return (0);
	if (curvertex->num_v == adjvertex->num_v)
		return (1);
	newadjv(&curvertex, adjvertex);
	newadjv(&adjvertex, curvertex);
	freeseveral((void **)&vname, (void **)&adjvname, 0, 0);
	return (1);
}
