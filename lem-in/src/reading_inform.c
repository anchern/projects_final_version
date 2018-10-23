/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_inform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:55:37 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 19:35:05 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static char	isvertex(char *line)
{
	int		i;

	if (line == 0 || *line == 0)
		return (0);
	if (*line == 'L' || (check_name(line) != 0))
		vertexfrmterr();
	i = 0;
	while (line[i] != ' ' && line[i] != 0)
		i++;
	if (line[i] != 0 && (ft_isdigit(line[i + 1]) || (line[i + 1] == '-' &&
							ft_isdigit(line[i + 2]))))
		line[i + 1] == '-' ? i += 2 : i++;
	else
		return (0);
	while (ft_isdigit(line[i]) && line[i] != 0)
		i++;
	if (line[i] != 0 && (ft_isdigit(line[i + 1]) || (line[i + 1] == '-' &&
							ft_isdigit(line[i + 2]))) && line[i] == ' ')
		line[i + 1] == '-' ? i += 2 : i++;
	else
		return (0);
	while ((ft_isdigit(line[i]) || line[i] == '-') && line[i] != 0)
		i++;
	return (line[i] == 0 ? (char)1 : (char)0);
}

static char	iseage(const char *line)
{
	int		i;

	if (line == 0 || *line == 0)
		return (0);
	i = 0;
	while (line[i] != 0 && line[i] != '-')
		i++;
	if (line[i] == '-' && i > 0)
		i++;
	else
		return (0);
	if (ft_strlen(&line[i]) == 0)
		return (0);
	while (line[i] != 0)
		i++;
	if (line[i] == 0)
		return (1);
	else
		return (0);
}

static char	isterminal(char **line, t_term *terminal)
{
	if (ft_strcmp(*line, "##start") == 0)
	{
		if (terminal->start == 1 || terminal->start == 2 || terminal->end == 1)
			terminal->end == 1 ? wrongtermformaterr() : doubletermerr();
		terminal->start = 1;
	}
	else if (ft_strcmp(*line, "##end") == 0)
	{
		if (terminal->end == 1 || terminal->end == 2 || terminal->start == 1)
			terminal->start == 1 ? wrongtermformaterr() : doubletermerr();
		terminal->end = 1;
	}
	else
		return (0);
	return (1);
}

static char	procinform(char **line, t_term *terminal, t_allv **allv, char *flag)
{
	if (isterminal(line, terminal))
		;
	else if (*line[0] == '#')
	{
		if (terminal->start == 1 || terminal->end == 1)
			wrongtermformaterr();
	}
	else if (isvertex(*line))
	{
		if (*flag)
			return (0);
		addvertex(*line, allv, terminal);
	}
	else if (iseage(*line))
	{
		*flag = 1;
		if (terminal->start == 1 || terminal->end == 1)
			wrongtermformaterr();
		if (!setadjv(*line, allv))
			non_existen_room_err();
	}
	else
		return (0);
	return (1);
}

t_allv		*reading(void)
{
	char	*line;
	t_term	*term;
	t_allv	*allv;
	char	flag;

	allv = 0;
	flag = 0;
	term = initterminal();
	while (get_next_line(0, &line) > 0)
	{
		ft_printf("%s\n", line);
		if (!procinform(&line, term, &allv, &flag))
			break ;
		ft_memdel((void **)&line);
	}
	free((void *)term);
	ft_memdel((void **)&line);
	return (allv);
}
