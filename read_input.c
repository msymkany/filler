/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:27:06 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/19 14:27:12 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

size_t		get_num(int *res, char *line, size_t i)
{
	while (!FLAG_NUM(line[i]))
		i++;
	while (FLAG_NUM(line[i]))
	{
		*res = (*res) * 10 + (line[i] - '0');
		i++;
	}
	return (i);
}

//void	print_arr(char **map, int row)
//{
//	int 	i;
//
//	i = 0;
//	while (i < row)
//	{
//		ft_printf("%s\n", map[i++]);
//	}
//}

void 	get_map(t_input *in)
{
	char 	*line;
	size_t	i;

	i = 0;
	line = NULL;
	if (!in->map)
	{
		in->map = (char **)malloc(sizeof(char*) * (in->map_x + 1));
		in->map[in->map_x] = NULL;
	}
	get_next_line(0, &line); // skip board info
	ft_strdel(&line);
	while (i < in->map_x)
	{
		get_next_line(0, &line);
		in->map[i++] = ft_strsub(line, 4, (size_t)in->map_y);
		ft_strdel(&line);
	}
//	print_arr(in->map, in->map_x); // test
}

void 	get_token(t_input *in)
{
	char 	*line;
	size_t 	i;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	i = get_num(&in->token_x, line, i);
	get_num(&in->token_y, line, i);
	ft_strdel(&line);
//	ft_printf("%d %d\n", in->token_x, in->token_y); // test
	in->token = (char **)malloc(sizeof(char*) * (in->token_x + 1));
	in->token[in->token_x] = NULL;
	i = 0;
	while (i < in->token_x)
	{
		get_next_line(0, &line);
		in->token[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
//	print_arr(in->token, in->token_x); // test
}

void	read_input(t_input *input, char *line)
{
	size_t 	i;

	i = 0;
	if (!input->map_x)
	{
		i = get_num(&input->map_x, line, 8);
		get_num(&input->map_y, line, i);
	}
	ft_strdel(&line);
//	ft_printf("%d %d\n", input->map_x, input->map_y); // test
	get_map(input);
	get_token(input);
}
