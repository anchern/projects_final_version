/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:36:19 by achernys          #+#    #+#             */
/*   Updated: 2018/10/17 19:30:33 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../lib/mylib/get_next_line.h"
# include "../lib/mylib/ft_printf/ft_printf.h"
# include <stdio.h>

# define FORM_ERR_EXIT 71
# define DBLTERM_ERR_EXIT 72
# define WRNGFRMTITER_ERR 73
# define REPEATCOORD_ERR 74
# define VERTEXFRMT_ERR 75
# define RD_ERR 76
# define NOROOM_ERR 77
# define INFORM_ERR 78
# define WAY_ERR 79
# define MEM_OUT_ERR 70

typedef struct		s_adjv
{
	int				num_v;
	char			*name_v;
	struct s_adjv	*next;
}					t_adjv;

typedef struct		s_allv
{
	char			terminal;
	unsigned long	antnum;
	int				num_v;
	int				value;
	char			*name_v;
	struct s_adjv	*adjv;
	struct s_allv	**adjarr;
	int				x;
	int				y;
	struct s_allv	*nextway;
	struct s_allv	*next;
}					t_allv;

typedef struct		s_term
{
	char			start;
	char			end;
}					t_term;

t_term				*initterminal(void);
void				addvertex(char *line, t_allv **allv, t_term *term);
char				setadjv(char *line, t_allv **allv);

void				printfrmterr(void);
void				doubletermerr(void);
void				wrongtermformaterr(void);
void				repeatcoorderr(void);
void				vertexfrmterr(void);
void				informerr(t_allv *allv);
void				readerr(void);
void				noroomerr(void);
void				noposswayerr(void);
void				no_ways_err(t_allv *allv);
void				non_existen_room_err(void);

t_allv				*reading(void);
char				checkinform(t_allv *allv);
t_allv				*possways(t_allv *allv, int maxadjvert, unsigned long ants);
t_allv				*findvbyname(char *name, t_allv *allv);
void				ants_gogogo(t_allv *endv, unsigned long ants, t_allv *allv);
void				uncsrwaysdel(t_allv **adjarr, int arrsize);
char				*get_namebynum(int num, t_allv *allv);
t_allv				*findbyterm(t_allv *allv, int term);

void				freeallv(t_allv *lst);
void				freeseveral(void **var0, void **var1, void **var2,
								void **var3);
void				freeadjv(t_adjv *adjv);
void				dfs(t_allv *allv);
t_allv				**sortvert(t_allv **vertarr);
int					vertarrlen(t_allv **vertarr);
void				print_start_cmt(char **line);
void				printants(t_allv *endv, int **antsroom, t_allv *allv);
void				arrnullify(int **arr, unsigned long arrsize);
char				iscomplete(const int *antsroom);
char				get_ant(t_allv *endv, int wcur, int **antsroom,
							unsigned long *ant);
char				check_name(char *line);
#endif
