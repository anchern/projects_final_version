/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 22:10:11 by achernys          #+#    #+#             */
/*   Updated: 2018/07/16 20:43:25 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int			main(void)
{
	char		*line;
	t_infrmtion	*inform;
	t_clctsubst	*substfigr;
	int			step;

	step = 0;
	line = 0;
	inform = infominit();
	get_next_line(0, &line);
	get_character(inform, line);
	while (1)
	{
		step++;
		if (line == 0)
			get_next_line(0, &line);
		fieldprocessing(inform, line);
		pieceprocessing(inform, line, step);
		set_cellval(inform);
		substfigr = substittfgr(inform, step);
		if (printresult(inform, substfigr))
			return (0);
		line = 0;
	}
}
