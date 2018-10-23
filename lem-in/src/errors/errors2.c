/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:33:22 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 19:35:05 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lem_in.h"

void	non_existen_room_err(void)
{
	ft_printf("{red}ERROR\n");
	ft_printf("Specified non-existent room.{eoc}\n");
	exit(FORM_ERR_EXIT);
}
