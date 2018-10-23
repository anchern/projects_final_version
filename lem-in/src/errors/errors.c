/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 20:01:32 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 19:45:09 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lem_in.h"

void	printfrmterr(void)
{
	ft_printf("{red}ERROR\n");
	ft_printf("Wrong format!{eoc}\n");
	ft_printf("{green}usage:{eoc}\nnumber_of_ants\t[unsigned integer "
					"(from 1 to 2147483647)$]\n"
					"the_rooms\t[any_name integer_coord_x integer_coord_y$]\n"
					"the_links\t[name_room1-name_room2$]\n");
	exit(WRNGFRMTITER_ERR);
}

void	doubletermerr(void)
{
	ft_printf("{red}ERROR\n");
	ft_printf("Wrong format!\n");
	ft_printf("Room start or room end indicated twice.{eoc}\n");
	exit(DBLTERM_ERR_EXIT);
}

void	wrongtermformaterr(void)
{
	ft_printf("{red}ERROR\n");
	ft_printf("Wrong format!\n");
	ft_printf("After the announcement of the start or end, a room must be "
				"declared.{eoc}\n");
	exit(WRNGFRMTITER_ERR);
}

void	repeatcoorderr(void)
{
	ft_printf("{red}ERROR\n");
	ft_printf("There are duplicate coordinates or room name.{eoc}\n");
	exit(REPEATCOORD_ERR);
}

void	vertexfrmterr(void)
{
	ft_printf("{red}ERROR\n");
	ft_printf("Wrong format!\n");
	ft_printf("The vertex can not begin with the letter 'L' and can not contain"
				" a symbol '-' and ' ' in the start and end name\n"
				"or in the edge declaration there is "
				"a space character.{eoc}\n");
	exit(VERTEXFRMT_ERR);
}
