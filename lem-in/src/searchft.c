/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:26:39 by achernys          #+#    #+#             */
/*   Updated: 2018/09/17 16:21:09 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char	*get_namebynum(int num, t_allv *allv)
{
	if (allv == 0)
		return (0);
	if (allv->num_v == num)
		return (allv->name_v);
	return (get_namebynum(num, allv->next));
}

t_allv	*findbyterm(t_allv *allv, int term)
{
	if (allv == 0)
		return (0);
	if (allv->terminal == term)
		return (allv);
	return (findbyterm(allv->next, term));
}
