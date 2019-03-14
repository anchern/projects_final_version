/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 05:48:31 by achernys          #+#    #+#             */
/*   Updated: 2019/02/28 06:17:24 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rotation_start(t_vector *vector, t_moves moves)
{
	double new_x;
	double new_y;
	double new_z;

	new_x = vector->p_start.x * cos(moves.rotation_y) * cos(moves.rotation_z) -
			vector->p_start.y * sin(moves.rotation_z) * cos(moves.rotation_y) +
			vector->p_start.z * sin(moves.rotation_y);
	new_y = vector->p_start.x * (sin(moves.rotation_x) * sin(moves.rotation_y) *
			cos(moves.rotation_z) + sin(moves.rotation_z) *
			cos(moves.rotation_x)) + vector->p_start.y *
			(-sin(moves.rotation_x) * sin(moves.rotation_y) *
			sin(moves.rotation_z) + cos(moves.rotation_z) *
			cos(moves.rotation_x)) - vector->p_start.z * sin(moves.rotation_x) *
			cos(moves.rotation_y);
	new_z = vector->p_start.x * (sin(moves.rotation_x) * sin(moves.rotation_z) -
			sin(moves.rotation_y) * cos(moves.rotation_x) *
			cos(moves.rotation_z)) + vector->p_start.y *
			(sin(moves.rotation_x) * cos(moves.rotation_z) +
			sin(moves.rotation_y) * sin(moves.rotation_z) *
			cos(moves.rotation_x)) + vector->p_start.z * cos(moves.rotation_x) *
			cos(moves.rotation_y);
	vector->p_start.x = new_x;
	vector->p_start.y = new_y;
	vector->p_start.z = new_z;
}

void	rotation_end(t_vector *vector, t_moves moves)
{
	double new_x;
	double new_y;
	double new_z;

	new_x = vector->p_end.x * cos(moves.rotation_y) * cos(moves.rotation_z) -
			vector->p_end.y * sin(moves.rotation_z) * cos(moves.rotation_y) +
			vector->p_end.z * sin(moves.rotation_y);
	new_y = vector->p_end.x * (sin(moves.rotation_x) * sin(moves.rotation_y) *
			cos(moves.rotation_z) + sin(moves.rotation_z) *
			cos(moves.rotation_x)) + vector->p_end.y * (-sin(moves.rotation_x) *
			sin(moves.rotation_y) * sin(moves.rotation_z) +
			cos(moves.rotation_z) * cos(moves.rotation_x)) - vector->p_end.z *
			sin(moves.rotation_x) * cos(moves.rotation_y);
	new_z = vector->p_end.x * (sin(moves.rotation_x) * sin(moves.rotation_z) -
			sin(moves.rotation_y) * cos(moves.rotation_x) *
			cos(moves.rotation_z)) + vector->p_end.y * (sin(moves.rotation_x) *
			cos(moves.rotation_z) + sin(moves.rotation_y) *
			sin(moves.rotation_z) * cos(moves.rotation_x)) + vector->p_end.z *
			cos(moves.rotation_x) * cos(moves.rotation_y);
	vector->p_end.x = new_x;
	vector->p_end.y = new_y;
	vector->p_end.z = new_z;
}

void	rotation(t_vector *vector, t_moves moves)
{
	rotation_start(vector, moves);
	rotation_end(vector, moves);
}
