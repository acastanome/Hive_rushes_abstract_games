/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:25:38 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/19 00:47:21 by spuustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santorini.h"
#include <unistd.h>

int		main(void)
{
	char buffer[100];
	int ret = 2;
	int e = 1;
	int array[25];
	int turn = 1;

	set_empty_stage(array);
	ft_putstr("N = start a new game\n");
	ft_putstr("E = clear the state.\n");
	ft_putstr("P = print the current state.\n");
	ft_putstr("S... = set stage (S 1.D 14.2 22.1 22.A ...)\n");
	ft_putstr("s = print the current state in string.\n");
	ft_putstr("T = play turn (T C 4 8 9\n");
	ft_putstr("ENTER to exit.\n");
	while (ret != 1)
	{
		ret = read(STDIN_FILENO, buffer, 1000);
		if (buffer[0] == 'T' && turn > 2)
			e = turn_parser(buffer, array);
		else if (buffer[0] == 'E' && ret == 2)
			set_empty_stage(array);
		else if (buffer[0] == 'P' && ret == 2)
			print_board(array);
		else if (buffer[0] == 's')
			print_state(array);
		else if (buffer[0] == 'S')
		{
			set_stage(array, buffer);
			if (is_game_won(array) == 0)
			{
				can_plr_move(array,1);
				can_plr_move(array,2);
				turn = 100;
			}
		}
		else if (buffer[0] == 'T')
		{
			if (new_game(array, buffer, turn) == 0)
				turn = 1;
			else
				turn ++;
		}
		else if (ret != 1)
			ft_putstr("invalid input, try again.\n");
		bzero(buffer, 100);
	}
	return (0);
}