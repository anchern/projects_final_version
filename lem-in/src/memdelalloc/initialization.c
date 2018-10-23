/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:03:39 by achernys          #+#    #+#             */
/*   Updated: 2018/07/31 14:06:04 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lem_in.h"

t_term	*initterminal(void)
{
	t_term	*term;

	term = (t_term *)ft_memalloc(sizeof(t_term *));
	term->start = 0;
	term->end = 0;
	return (term);
}
