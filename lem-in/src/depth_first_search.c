/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_first_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 15:13:39 by achernys          #+#    #+#             */
/*   Updated: 2018/08/04 16:28:41 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static char	allpassed(t_allv *allv)
{
	int		i;

	i = 0;
	while (allv->adjarr[i] != 0)
	{
		if (allv->adjarr[i]->value > allv->value + 1 ||
			allv->adjarr[i]->value == -1)
			return (0);
		i++;
	}
	return (1);
}

void		dfs(t_allv *allv)
{
	int		i;

	if (allv->terminal == -1 || allpassed(allv))
		return ;
	i = 0;
	while (allv->adjarr[i] != 0)
	{
		if (allv->adjarr[i]->value == -1 || allv->value + 1 <
												allv->adjarr[i]->value)
		{
			allv->adjarr[i]->value = allv->value + 1;
			dfs(allv->adjarr[i]);
		}
		i++;
	}
}
