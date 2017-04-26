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
	int 		rival_x; // direction ver.1
	int 		rival_y; // direction ver.1
//	int 		my_x; // starting point ver.1
//	int 		my_y; // starting point ver.1
	int 		res_x;
	int 		res_y;
	int			dist_sum;
//	char 		in; // test side
	int 		**dist_map;
}				t_input;

void			clean_struct(t_input *in);
t_input			*initialize_struct(void);
void			delete_struct(t_input **in);

void			read_input(t_input *input, char *line);
void 			get_token(t_input *in);
void 			get_map(t_input *in);
size_t			get_num(int *res, char *line, size_t i);

//void			put_token(t_input *in);
//void			place_token(t_input *in);

int				module(int i);
void			init_array(t_input *in);
void			get_rival(t_input *in);
//void			first_calculate_distance(t_input *in);
void			calculate_distance(t_input *in);

void			place_on_map(t_input *in);
void			write_distance(t_input *in);
int				find_best_place(t_input *in);
int				check_placement(int	x, int y, t_input *in);

//test
void			print_arr(char **map, int row);
void			print_int_arr(int **map, int row, int col);

#endif
