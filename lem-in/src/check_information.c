/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_information.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:28:17 by achernys          #+#    #+#             */
/*   Updated: 2018/07/31 17:25:09 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void	presence_strt_end_eage(t_allv *allv, char *eage, char *start,
										char *end)
{
	if (allv == 0)
		return ;
	if (allv->adjv != 0)
		*eage = 1;
	if (allv->terminal == 1)
		*start = 1;
	if (allv->terminal == -1)
		*end = 1;
	presence_strt_end_eage(allv->next, eage, start, end);
}

char		checkinform(t_allv *allv)
{
	char	start;
	char	end;
	char	eage;

	start = 0;
	end = 0;
	eage = 0;
	presence_strt_end_eage(allv, &eage, &start, &end);
	return (start && end && eage);
}
