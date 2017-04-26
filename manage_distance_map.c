/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_distance_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:36:50 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/24 17:36:56 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_array(t_input *in)
{
	size_t 	i;
	size_t 	j;

	i = 0;
	while (i < in->map_x)
	{
		j = 0;
		while (j < in->map_y)
		{
			in->dist_map[i][j++] = 0;
		}
		i++;
	}
}

void	get_rival(t_input *in)
{
	int		i;
	int 	j;

	i = 0;
	while (in->map[i])
	{
		j = 0;
		while (in->map[i][j])
		{
			if (in->map[i][j] == R(in->sign))
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

int 	module(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

//void	first_calculate_distance(t_input *in)
//{
//	int		i;
//	int		j;
//
//	i = 0;
//	while (i < in->map_x)
//	{
//		j = 0;
//		while (j < in->map_y)
//		{
//			if (in->map[i][j] == '.')
//				in->dist_map[i][j] = module(i - in->rival_x) + module(j - in->rival_y);
//			if (in->map[i][j] == in->sign)
//				in->dist_map[i][j] = -2;
//			if (in->map[i][j] == R(in->sign))
//				in->dist_map[i][j] = -1;
//			j++;
//		}
//		i++;
//	}
//}

void	calculate_distance(t_input *in)
{
	int		i;
	int		j;
	int 	distance;

	i = 0;
	distance = 0;
	while (i < in->map_x)
	{
		j = 0;
		while (j < in->map_y)
		{

			if (in->map[i][j] == '.')
			{
				distance = module(i - in->rival_x) + module(j - in->rival_y);
//				ft_printf("%d\n", distance); // test
				if (in->dist_map[i][j] > distance || in->dist_map[i][j] == 0)
				{
					in->dist_map[i][j] = distance;
				}
			}
			j++;
		}
		i++;
	}
}
