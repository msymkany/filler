/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:14:34 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/17 15:14:52 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char 	*line;
	t_input	*input;

	line = NULL;
	input = initialize_struct();
	get_next_line(0, &line);
//	ft_printf("%s\n", line); // test
	if (ft_strnequ(line, "$$$ exec p1", 11))
		input->sign = 'O';
	else
		input->sign = 'X';
//	ft_printf("%c\n", input->sign); // test
	ft_strdel(&line);
	while (get_next_line(0, &line))
	{
		read_input(input, line);
//		ft_printf("%s\n", "finita"); // test
		place_token(input);
		clean_struct(input);
	}
//	delete_struct(&input);
	return (0);
}
