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
		if (!in->map[++x] || step > 1) //(!map[x + i])
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

//int		get_rival(t_input *in)
//{
//	return ();
//}

//int 	put_towards(t_input *in)
//{
//	int		i;
//	int 	j;
//	int		m;
//	int 	n;
//
//	i = ;
//	while (in->map[i])
//	{
//		j = 0;
//		while (in->map[i][j])
//		{
//
//			j++;
//		}
//		i++;
//	}
//
//	return (1);
//}

void	put_token(t_input *in)
{
//	if (put_towards(in))
//	{
//		ft_printf("%d %d\n", in->res_x, in->res_y);
//	}
//	else if (get_rival(in))
//	{
//		ft_printf("%d %d\n", in->res_x, in->res_y);
//	}
//	else
//	ft_printf("%d %d\n", in->res_x, in->res_y);
	find_free_place(in);
	ft_printf("%d %d\n", in->res_x, in->res_y);
	return ;
}