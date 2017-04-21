/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:03:39 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/19 15:03:43 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_my_position(t_input *in)
{
	int		i;
	int 	j;

	i = 0;
	while (in->map[i])
	{
		j = 0;
		while (in->map[i][j])
		{
			if (in->map[i][j] == in->sign)
			{
//				ft_printf("%d %d\n", i, j); // test
				in->rival_x -= i;
				in->rival_y -= j;
				in->my_x = i;
				in->my_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_direction(t_input *in, char rival)
{
	int		i;
	int 	j;

	i = 0;
	while (in->map[i])
	{
		j = 0;
		while (in->map[i][j])
		{
			if (in->map[i][j] == rival)
			{
//				ft_printf("%d %d\n", i, j); // test
				in->rival_x = i;
				in->rival_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

//void	print_coordinates(int x, int y)
//{
//	ft_printf("%d %d\n", x, y);
//}
//print_coordinates(in->res_x, in->res_y);



void	place_token(t_input *in)
{
	char	rival;

	rival = (in->sign == 'O') ? 'X' : 'O';
	if (in->rival_x == -2147483648)
	{
		get_direction(in, rival);
		get_my_position(in);
		in->rival_x = (in->rival_x > 0) ? 1 : -1;
		in->rival_y = (in->rival_y > 0) ? 1 : -1;
//		ft_printf("%d %d\n", in->rival_x, in->rival_y); // test
	}
	put_token(in);
}
