/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 06:23:57 by achernys          #+#    #+#             */
/*   Updated: 2019/02/28 06:24:29 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	move(t_vector *vector, int move_x, int move_y)
{
	vector->p_start.x += move_x;
	vector->p_end.x += move_x;
	vector->p_start.y += move_y;
	vector->p_end.y += move_y;
}
