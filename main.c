/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:25:38 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/19 01:30:02 by acastano         ###   ########.fr       */
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
	ft_putstr("\n\tWelcome to the game of Santorini!\n\n");

	ft_putstr("\tOn their first turn, each player must place both builders (T A 3 B 10)\n\tAfter that:");
	ft_putstr("\tT = play turn (T C 4 8 9)\n\t\t\t(T - player to move - where to move from - where to move to - where to build)\n");
	ft_putstr("\tS = set stage (S 1.D 14.2 22.1 22.A ...)\n");
	ft_putstr("\tP = print the current state.\n");
	ft_putstr("\tPS = print the current state in string.\n");
	ft_putstr("\tC = clear the state.\n");
	ft_putstr("\tENTER to exit.\n\n");
	ft_putstr("\n\tGo ahead, you can start playing now!\n\n");
	while (ret != 1)
	{
		ret = read(STDIN_FILENO, buffer, 1000);
		if (buffer[0] == 'T' && turn > 2)
			e = turn_parser(buffer, array);
		else if (buffer[0] == 'C' && ret == 2)
			set_empty_stage(array);
		else if (buffer[0] == 'P' && ret == 2)
			print_board(array);
		else if (buffer[0] == 'P' && buffer[1] == 'S' && ret == 3)
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
