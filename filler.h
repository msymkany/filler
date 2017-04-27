/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:15:03 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/17 15:16:19 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/includes/libft.h"
# include "libft/includes/libftprintf.h"
# include <unistd.h>
# include <stdlib.h>
# define R(x) ((x == 'O') ? 'X' : 'O')

typedef struct	s_input
{
	char		sign;
	int			map_x;
	int			map_y;
	char		**map;
	int			token_x;
	int			token_y;
	char		**token;
	int			rival_x;
	int			rival_y;
	int			res_x;
	int			res_y;
	int			dist_sum;
	int			**dist_map;
}				t_input;

void			clean_struct(t_input *in);
t_input			*initialize_struct(void);
void			delete_struct(t_input **in);

void			read_input(t_input *input, char *line);
void			get_token(t_input *in);
void			get_map(t_input *in);
size_t			get_num(int *res, char *line, size_t i);

int				module(int i);
void			init_array(t_input *in);
void			get_rival(t_input *in);
void			calculate_distance(t_input *in);

void			place_on_map(t_input *in);
void			write_distance(t_input *in);
int				find_best_place(t_input *in);
int				check_placement(int	x, int y, t_input *in);

#endif
