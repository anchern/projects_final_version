/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:22:09 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 19:28:57 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char	get_ant(t_allv *endv, int wcur, int **antsroom, unsigned long *ant)
{
	if (endv->adjarr[wcur]->antnum != 0)
	{
		(*antsroom)[*ant - 1] = endv->num_v;
		endv->adjarr[wcur]->antnum--;
		*ant += 1;
		return (0);
	}
	else
		return (1);
}

char	check_name(char *line)
{
	int i;

	i = 0;
	if (line[i] == ' ')
		vertexfrmterr();
	if (line[i] == 0)
		vertexfrmterr();
	if (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i] != 0)
	{
		if (line[i] == '-' && ft_strchr(line, ' '))
			vertexfrmterr();
		i++;
	}
	return (0);
}
