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
	char 		sign;
	int 		map_x; // first map parameters than token coordinates
	int			map_y;
	char		**map;
	int			token_x;
	int 		token_y;
	char 		**token;
	int 		rival_x; // square
	int 		rival_y; // square
	int 		my_x; // square
	int 		my_y;
	int 		res_x;
	int 		res_y;
}				t_input;

void			clean_struct(t_input *in);
t_input			*initialize_struct(void);
void			delete_struct(t_input **in);

void			read_input(t_input *input, char *line);
void 			get_token(t_input *in);
void 			get_map(t_input *in);
size_t			get_num(int *res, char *line, size_t i);


void			put_token(t_input *in);
void			place_token(t_input *in);


#endif
