/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:54:46 by achernys          #+#    #+#             */
/*   Updated: 2018/07/16 16:24:28 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_infrmtion	*infominit(void)
{
	t_infrmtion *inform;

	inform = (t_infrmtion *)ft_memalloc(sizeof(t_infrmtion));
	inform->character = 0;
	inform->exception = 0;
	inform->piece.width = 0;
	inform->piece.height = 0;
	inform->piece.map = 0;
	inform->board.width = 0;
	inform->board.height = 0;
	inform->board.map = 0;
	return (inform);
}

void		informfree(t_infrmtion *inform)
{
	int		i;

	i = 0;
	while (i < inform->board.height)
	{
		ft_memdel((void **)&(inform->board.map[i]));
		i++;
	}
	i = 0;
	while (i < inform->piece.height)
	{
		ft_memdel((void **)&(inform->piece.map[i]));
		i++;
	}
	free((void *)inform->board.map);
	free((void *)inform->piece.map);
	free((void *)inform);
}

void		mapfree(t_infrmtion *inform)
{
	int		i;

	i = 0;
	while (i < inform->board.height)
	{
		ft_memdel((void **)&(inform->board.map[i]));
		i++;
	}
	i = 0;
	while (i < inform->piece.height)
	{
		ft_memdel((void **)&(inform->piece.map[i]));
		i++;
	}
	free((void *)inform->board.map);
	free((void *)inform->piece.map);
	inform->piece.width = 0;
	inform->piece.height = 0;
	inform->piece.map = 0;
	inform->board.map = 0;
}
