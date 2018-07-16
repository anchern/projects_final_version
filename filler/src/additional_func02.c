/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:08:35 by achernys          #+#    #+#             */
/*   Updated: 2018/07/16 20:49:57 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		**copymap(t_infrmtion *inform)
{
	int		**map;
	int		i;
	int		j;

	map = (int **)ft_memalloc(inform->board.height * sizeof(int *));
	i = 0;
	while (i < inform->board.height)
	{
		map[i] = (int *)ft_memalloc(inform->board.width * sizeof(int));
		i++;
	}
	i = 0;
	while (i < inform->board.height)
	{
		j = 0;
		while (j < inform->board.width)
		{
			map[i][j] = inform->board.map[i][j];
			j++;
		}
		i++;
	}
	return (map);
}

void	delmychar(t_infrmtion *inform)
{
	int		i;
	int		j;

	i = 0;
	while (i < inform->board.height)
	{
		j = 0;
		while (j < inform->board.width)
		{
			if (inform->board.map[i][j] == -2)
				inform->board.map[i][j] = -1;
			j++;
		}
		i++;
	}
}

void	addmychar(t_infrmtion *inform, int **copymap)
{
	int		i;
	int		j;

	i = 0;
	while (i < inform->board.height)
	{
		j = 0;
		while (j < inform->board.width)
		{
			if (copymap[i][j] == -2)
				inform->board.map[i][j] = -2;
			j++;
		}
		i++;
	}
}

void	freememmap(int **map, t_infrmtion *inform)
{
	int		i;

	i = 0;
	while (i < inform->board.height)
	{
		free((void *)map[i]);
		map[i] = 0;
		i++;
	}
	free((void *)map);
	map = 0;
}

char	printresult(t_infrmtion *inform, t_clctsubst *substfigr)
{
	if (substfigr == 0)
	{
		ft_printf("0 0");
		informfree(inform);
		return (1);
	}
	ft_printf("%d %d\n", substfigr->y, substfigr->x);
	free((void *)substfigr);
	mapfree(inform);
	return (0);
}
