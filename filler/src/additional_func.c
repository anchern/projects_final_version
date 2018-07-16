/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:29:48 by achernys          #+#    #+#             */
/*   Updated: 2018/07/16 20:42:32 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_clctsubst	*addforward(t_clctsubst *clctsubst, t_clctsubst *newelem)
{
	newelem->next = clctsubst;
	return (newelem);
}

t_clctsubst	*copyelem(t_clctsubst *elem)
{
	t_clctsubst	*newelem;

	if (elem == 0)
		return (0);
	newelem = (t_clctsubst *)ft_memalloc(sizeof(t_clctsubst));
	newelem->next = 0;
	newelem->sumval = elem->sumval;
	newelem->x = elem->x;
	newelem->y = elem->y;
	return (newelem);
}

void		freelst(t_clctsubst *lst)
{
	if (lst == 0)
		return ;
	freelst(lst->next);
	free((void *)lst);
	lst = 0;
}

t_clctsubst	*findminy(t_clctsubst *clctsubst, t_clctsubst *min)
{
	if (clctsubst == 0 || min == 0)
		return (0);
	if (clctsubst->next == 0)
	{
		if (clctsubst->y < min->y)
			min = clctsubst;
		return (min);
	}
	if (clctsubst->y < min->y)
		min = clctsubst;
	return (findminy(clctsubst->next, min));
}
