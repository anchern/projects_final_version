/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 19:32:12 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 20:04:12 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lem_in.h"

void	readerr(void)
{
	ft_printf("{red}ERROR\n");
	ft_printf("Read error!{eoc}\n");
	exit(RD_ERR);
}

void	noroomerr(void)
{
	ft_printf("{red}ERROR\n");
	ft_printf("No rooms have been entered.{eoc}\n");
	exit(NOROOM_ERR);
}

void	informerr(t_allv *allv)
{
	freeallv(allv);
	ft_printf("{red}ERROR\n");
	ft_printf("Perhaps the start or end rooms or at least one edge were not "
					"specified.{eoc}\n");
	exit(INFORM_ERR);
}

void	noposswayerr(void)
{
	ft_printf("{red}ERROR\n");
	ft_printf("There is no nextway to spend ants.{eoc}\n");
	exit(WAY_ERR);
}

void	no_ways_err(t_allv *allv)
{
	ft_printf("{red}ERROR\n");
	ft_printf("There are no ways from the start to the end.{eoc}\n");
	freeallv(allv);
	exit(WRNGFRMTITER_ERR);
}
