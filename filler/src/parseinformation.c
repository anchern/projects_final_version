/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseinformation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:56:34 by achernys          #+#    #+#             */
/*   Updated: 2018/07/16 16:24:28 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void		get_character(t_infrmtion *inform, char *line)
{
	if (ft_strstr(line, "exec p1") != 0)
		inform->character = 'O';
	else
		inform->character = 'X';
}

void		get_sizepicbrd(char *str, int *width, int *height)
{
	int		i;

	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	*height = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	*width = ft_atoi(&str[i]);
}

int			*procmapbrd(char *str, size_t size, char character)
{
	int		*out;
	int		i;

	i = 0;
	out = (int *)malloc(size * sizeof(int));
	while (str[i] != 0)
	{
		if (str[i] == '.')
			out[i] = -1;
		else if (str[i] == character || str[i] == character + 32)
			out[i] = -2;
		else
			out[i] = 0;
		i++;
	}
	ft_memdel((void **)&str);
	return (out);
}

static int	*procpiece(char *str, size_t size)
{
	int		*out;
	int		i;

	i = 0;
	out = (int *)malloc(sizeof(int) * size);
	while (str[i] != 0)
	{
		if (str[i] == '*')
			out[i] = 1;
		else
			out[i] = 0;
		i++;
	}
	free((void *)str);
	return (out);
}

int			**get_mapfield(t_infrmtion *inform, int **map, int map_height)
{
	char	*line;
	int		i;

	i = 0;
	map = (int **)malloc((size_t)map_height * sizeof(int *));
	while (i < map_height)
	{
		get_next_line(0, &line);
		if (ft_isdigit(line[0]))
			map[i] = procmapbrd(ft_strdup(&line[4]),
								(size_t)inform->board.width,
								inform->character);
		else
			map[i] = procpiece(strdup(line), (size_t)inform->piece.width);
		i++;
		ft_memdel((void **)&line);
	}
	return (map);
}
