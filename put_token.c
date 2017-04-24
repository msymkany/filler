/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:31:13 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/21 17:31:20 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	check_placement(int	x, int y, t_input *in)
{
	int		i;
	int 	j;
	int 	step;

	i = 0;
	step = 0;
	while (in->token[i])
	{
		j = 0;
		while (in->token[i][j])
		{
			if (!in->map[x][y + j])
				return (0);
			if (in->token[i][j] == '*' && in->map[x][y + j] == in->sign)
				step++;
			if (in->token[i][j] == '*' && in->map[x][y + j] == R(in->sign))
				return (0);
			j++;
		}
		i++;
		if (!in->map[++x] || step > 1)
			return (0);
	}
	if (!step)
		return (0);
	return (1);
}

int 	find_free_place(t_input *in)
{
	int		i;
	int 	j;

	i = 0;
	while (in->map[i])
	{
		j = 0;
		while (in->map[i][j])
		{
			if (check_placement(i, j, in))
			{
				in->res_x = i;
				in->res_y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int 	find_free_place_plus(t_input *in)
{
	int		i;
	int 	j;

	i = 0;
	while (i < in->my_x)
	{
		j = 0;
		while (j < in->my_y)
		{
			if (check_placement(i, j, in))
			{
				in->res_x = i;
				in->res_y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}


int 	find_free_place_side(t_input *in)
{
	int		i;
	int 	j;

	i = ((in->my_x - in->token_x < 0) ? 0 : in->my_x - in->token_x);
	while (i < in->my_x)
	{
		j = 0;
		while (j < in->my_y)
		{
			if (check_placement(i, j, in))
			{
				in->res_x = i;
				in->res_y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	put_token(t_input *in)
{
	if (find_free_place_side(in) && !in->in)
	{
		in->in = 1;
		ft_printf("%d %d\n", in->res_x, in->res_y);
	}
	else if (find_free_place_plus(in))
	{
		ft_printf("%d %d\n", in->res_x, in->res_y);
		in->in = 0;
	}
	else
	{
		find_free_place(in);
		ft_printf("%d %d\n", in->res_x, in->res_y);
		in->in = 0;
	}
	return ;
}


$$$ exec p1
Plateau 15 17:
	01234567890123456
000 .................
001 .................
002 .................
003 .................
004 .................
005 .................
006 .................
007 .................
008 ..O..............
009 .................
010 .................
011 .................
012 ..............X..
013 .................
014 .................
Piece 2 3:
***
...

Plateau 15 17:
	01234567890123456
000 .................
001 .................
002 .................
003 .................
004 .................
005 .................
006 .................
007 .................
008 ..OOO............
009 .................
010 .................
011 ..............X..
012 ..............X..
013 .................
014 .................
Piece 2 1:
*
*