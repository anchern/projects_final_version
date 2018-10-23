/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 19:17:21 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 20:34:37 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static unsigned long	getants(char **allinform)
{
	int				i;
	char			*line;
	unsigned long	ants;

	line = 0;
	print_start_cmt(&line);
	*allinform = ft_strnew(ft_strlen(line) + 1);
	ft_strcpy(*allinform, line);
	(*allinform)[ft_strlen(line)] = '\n';
	i = 0;
	while (line[i] != 0)
	{
		if (!ft_isdigit(line[i]))
		{
			printfrmterr();
			ft_memdel((void **)&line);
			exit(FORM_ERR_EXIT);
		}
		i++;
	}
	ants = (unsigned int)ft_atoi(line);
	ft_memdel((void **)&line);
	return (ants);
}

void					get_numadjv(t_adjv *adjv, int *num)
{
	if (adjv == 0)
		return ;
	*num += 1;
	get_numadjv(adjv->next, num);
}

int						get_maxadjv(t_allv *allv)
{
	t_allv	*curvert;
	int		num;
	int		maxnum;

	curvert = allv;
	num = 0;
	maxnum = 0;
	while (curvert != 0)
	{
		get_numadjv(curvert->adjv, &num);
		if (maxnum < num)
			maxnum = num;
		num = 0;
		curvert = curvert->next;
	}
	return (maxnum);
}

int						main(void)
{
	t_allv			*allv;
	char			*allinform;
	unsigned long	ants;
	t_allv			*endv;

	ants = getants(&allinform);
	if (ants < 1 || ants > 2147483647)
	{
		ft_memdel((void **)&allinform);
		printfrmterr();
	}
	ft_printf("%s", allinform);
	ft_memdel((void **)&allinform);
	allv = reading();
	if (!checkinform(allv))
		informerr(allv);
	endv = possways(allv, get_maxadjv(allv), ants);
	if (endv->adjarr[0] == 0)
		no_ways_err(allv);
	ants_gogogo(endv, ants, allv);
	freeallv(allv);
	return (0);
}
