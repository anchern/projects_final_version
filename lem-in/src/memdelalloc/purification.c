/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 20:11:03 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 20:34:37 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lem_in.h"

void		freeseveral(void **var0, void **var1, void **var2, void **var3)
{
	if (var0 && *var0)
		ft_memdel(var0);
	if (var1 && *var1)
		ft_memdel(var1);
	if (var2 && *var2)
		ft_memdel(var2);
	if (var3 && *var3)
		ft_memdel(var3);
}

void		freeadjv(t_adjv *adjv)
{
	if (adjv == 0)
		return ;
	freeadjv(adjv->next);
	ft_memdel((void **)&adjv->name_v);
	free((void *)adjv);
	adjv = 0;
}

void		freeallv(t_allv *lst)
{
	if (lst == 0)
		return ;
	freeallv(lst->next);
	free(lst->adjarr);
	lst->adjarr = 0;
	free(lst->name_v);
	free((void *)lst);
}
