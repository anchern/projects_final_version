/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 06:24:32 by achernys          #+#    #+#             */
/*   Updated: 2019/02/28 06:26:03 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	zoom(t_vector *vector, int zoom)
{
	vector->p_start.x *= zoom;
	vector->p_start.y *= zoom;
	vector->p_end.x *= zoom;
	vector->p_end.y *= zoom;
	vector->p_start.z *= zoom;
	vector->p_end.z *= zoom;
}
