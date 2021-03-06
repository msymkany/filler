/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_on_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:49:37 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/24 12:49:44 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	write_distance(t_input *in)
{
	int		i;
	int		j;

	i = 0;
	while (in->map[i])
	{
		j = 0;
		while (in->map[i][j])
		{
			if (in->map[i][j] == R(in->sign) && in->dist_map[i][j] >= 0)
			{
				in->dist_map[i][j] = -1;
				in->rival_x = i;
				in->rival_y = j;
				calculate_distance(in);
			}
			else if (in->map[i][j] == in->sign)
				in->dist_map[i][j] = -2;
			j++;
		}
		i++;
	}
}

int		check_placement(int x, int y, t_input *in)
{
	int		i;
	int		j;
	int		step;
	int		d_sum;

	i = -1;
	step = 0;
	d_sum = 0;
	while (in->token[++i])
	{
		if (i && !in->map[++x])
			return (0);
		j = -1;
		while (in->token[i][++j])
		{
			if (!in->map[x][y + j] ||
				(in->token[i][j] == '*' && in->map[x][y + j] == R(in->sign)))
				return (0);
			else if (in->token[i][j] == '*' && in->map[x][y + j] == in->sign)
				step++;
			else if (in->map[x][y + j] == '.')
				d_sum = d_sum + in->dist_map[x][y + j];
		}
	}
	return ((step != 1) ? 0 : d_sum);
}

int		find_best_place(t_input *in)
{
	int		i;
	int		j;
	int		dist;

	i = 0;
	while (in->map[i])
	{
		j = 0;
		while (in->map[i][j])
		{
			dist = check_placement(i, j, in);
			if (dist && dist < in->dist_sum)
			{
				in->res_x = i;
				in->res_y = j;
				in->dist_sum = dist;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	place_on_map(t_input *in)
{
	write_distance(in);
	find_best_place(in);
	ft_printf("%d %d\n", in->res_x, in->res_y);
}
