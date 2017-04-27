/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:15:34 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/19 11:15:44 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		clean_struct(t_input *in)
{
	int		i;

	i = 0;
	in->token_x = 0;
	in->token_y = 0;
	in->res_x = 0;
	in->res_y = 0;
	while (in->token[i])
	{
		ft_strdel(&in->token[i++]);
	}
	free(in->token);
	in->token = NULL;
	i = 0;
	while (in->map[i])
	{
		ft_strdel(&in->map[i++]);
	}
	in->dist_sum = 2147483647;
}

t_input		*initialize_struct(void)
{
	t_input		*in;

	in = (t_input *)malloc(sizeof(t_input));
	in->sign = 0;
	in->map_x = 0;
	in->map_y = 0;
	in->map = NULL;
	in->token_x = 0;
	in->token_y = 0;
	in->token = NULL;
	in->rival_x = 0;
	in->rival_y = 0;
	in->res_x = 0;
	in->res_y = 0;
	in->dist_sum = 2147483647;
	in->dist_map = NULL;
	return (in);
}

void		delete_struct(t_input **in)
{
	int		i;

	i = 0;
	while (i < (*in)->map_x)
	{
		free((*in)->dist_map[i++]);
	}
	free(*in);
	*in = NULL;
}
