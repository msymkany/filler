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

void	clean_struct(t_input *in)
{
	int 	i;

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
		ft_strdel(&in->map[i++]); // or strdel
	}
}

t_input		*initialize_struct(void)
{
	t_input 	*in;

	in = (t_input *)malloc(sizeof(t_input));
	in->sign = 0;
	in->map_x = 0;
	in->map_y = 0;
	in->map = NULL;
	in->token_x = 0;
	in->token_y = 0;
	in->token = NULL;
	in->rival_x = -2147483648;
	in->rival_y = -2147483648;
	in->res_x = 0;
	in->res_y = 0;
	return (in);
}

void	delete_struct(t_input **in)
{
	int 	i;

	i = 0;
	while ((*in)->token[i])
	{
		free((*in)->token[i++]);
	}
	free((*in)->token);
	(*in)->token = NULL;
	i = 0;
	while ((*in)->map[i])
	{
		free((*in)->map[i++]);
	}
	free((*in)->map);
	(*in)->map = NULL;
	free(*in);
	*in = NULL;
}