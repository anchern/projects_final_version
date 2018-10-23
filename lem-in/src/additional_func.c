/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 18:32:37 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 19:17:42 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static char				isnotcmt(char *line)
{
	if (line[0] != '#')
		return (1);
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		printfrmterr();
	ft_printf("%s\n", line);
	return (0);
}

void					print_start_cmt(char **line)
{
	while (1)
	{
		if (get_next_line(0, line) <= 0)
			readerr();
		if (isnotcmt(*line))
			break ;
		ft_memdel((void **)line);
	}
}

void					printants(t_allv *endv, int **antsroom, t_allv *allv)
{
	int		i;
	char	flag;

	i = 0;
	flag = 0;
	while ((*antsroom)[i] != -4 && (*antsroom)[i] != -1)
	{
		if ((*antsroom)[i] == -2)
		{
			i++;
			continue ;
		}
		if ((*antsroom)[i] >= 0)
		{
			if (flag)
				ft_printf(" ");
			ft_printf("L%d-%s", i + 1, get_namebynum((*antsroom)[i], allv));
			flag = 1;
		}
		if ((*antsroom)[i] == endv->num_v)
			(*antsroom)[i] = -2;
		i++;
	}
}

void					arrnullify(int **arr, unsigned long arrsize)
{
	unsigned long	i;

	i = 0;
	while (i < arrsize)
	{
		(*arr)[i] = -1;
		i++;
	}
	(*arr)[i] = -4;
}

char					iscomplete(const int *antsroom)
{
	int		i;

	i = 0;
	while (antsroom[i] != -4)
	{
		if (antsroom[i] >= -1)
			return (0);
		i++;
	}
	return (1);
}
