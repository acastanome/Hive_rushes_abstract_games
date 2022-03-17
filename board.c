/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:34:30 by acastano          #+#    #+#             */
/*   Updated: 2022/03/17 23:06:23 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "santorini.h"
#include <unistd.h>
#include <stdio.h>//printf

//-------------------------------------------------------------------------
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

/*
 * ft_move() takes an int array representing the board (and it's content), an
 * int representing the player_id, an int representing the index of square we want
 * to move from, and an int representing the index of square we want to move to.
 * Return values: Calls error and returns 0 if failed, 1 if it moves.
 */
int	ft_move(int *board, int player_id, int pos1, int pos2)
{
	if (is_player_id(board[pos1], player_id) == 0)
	{
		error("Player not there");
		return (0);
	}
	printf("hello1\n");
	if (is_position_buildable(board[pos2]) == 0)
	{
		error("Occupied");
		return (0);
	}
	printf("hello2\n");
	if (is_adjacent(pos1, pos2) == 0)
	{
		error("Not adjacent");
		return (0);
	}
	printf("hello3\n");
	if (is_level_ok(pos1, pos2) == 0)
	{
		error("Level height");
		return (0);
	}
	printf("hello4\n");
	board[pos1] = (board[pos1] - player_id);
	board[pos2] = (board[pos2] + player_id);
	return (1);
}

int	ft_build(int *board, int player_position, int position)
{
	if (is_adjacent(player_position, position) == 0)
	{
		error("Not adjacent");
		return (0);
	}
	if (is_position_buildable(board[position]) == 0)
	{
		printf("pos build prob\n");
		error ("Occupied");
		return (0);
	}
	board[position] = board[position] + 1;
	return (1);
}

int	main(void)
{
/*
	char	player_A = 'A';
	char	player_B = 'B';
	char	player_C = 'C';
	char	player_D = 'D';
*/

/* 		Board						Array
 * 1	2	3	4	5			0	1	2	3	4
 * 6	7	8	9	10			5	6	7	8	9
 * 11	12	13	14	15
 * 16	17	18	19	20
 * 21	22	23	24	25
 */

	int	board[25];
	int	i;

	i  = 0;
	while (i < 25)
	{
		board[i] = 0;
		i++;
	}

	board[3] = 10;
	i = 0;
	while (i < 25)
	{
		printf("%d, ", board[i]);
		if ((i + 1) % 5 == 0)
			printf("\n");
		i++;
	}
	printf("\n");

	ft_build(board, 3, 4);
	printf("1. Value after building in empty square is %d\n", board[4]);
	ft_build(board, 3, 4);
	printf("2. Value after building in empty square is %d\n", board[4]);
	ft_build(board, 3, 4);
	printf("3. Value after building in empty square is %d\n", board[4]);

	i  = 0;
	while (i < 25)
	{
		printf("%d, ", board[i]);
		if ((i + 1) % 5 == 0)
			printf("\n");
		i++;
	}
	printf("\n");

	printf("4. Board, 10, 3, 2\nValue before moving from pos1 (%d) to pos2 (%d)\n", board[3], board[2]);
	ft_move(board, 10, 3, 2);
	printf("5. Value after moving from pos1 (%d) to pos2 (%d)\n", board[3], board[2]);
	return (0);
}
