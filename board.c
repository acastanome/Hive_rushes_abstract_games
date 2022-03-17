/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:34:30 by acastano          #+#    #+#             */
/*   Updated: 2022/03/17 19:39:23 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "santorini.h"
#include <unistd.h>
#include <stdio.h>//printf

/*
 * is_player_id() checks if there is the right player in that square
 * Return values: 1 if there is the correct player, 0 if not.
 */
int	is_player_id(int square_status, int player)
{
	if ((square_status / 10) == player)
		return (1);
	return (0);
}

int	ft_move(int *map, int player, int pos1, int pos2)
{
	if ()
	return (0);
}


/*
 * is_player() checks if there is a player in that square
 * Return values: 1 if there is player, 0 if not.
 */
int	is_player(int square_status)
{
	if ((square_status / 10) != 0)
		return (1);
	return (0);
}

/*
 * is_dome() checks if there is already a dome in that square
 * Return values: 1 if there is a dome, 0 if not.
 */
int	is_dome(int square_status)
{
	if ((square_status % 10) == 4)
		return (1);
	return (0);
}

/*
 * ft_build() takes an int array representing the board (and it's content)
 * and an int representing the index of square we want to build in.
 * Return values: Calls error and returns 0 if failed, 1 if it builds.
 */
int	ft_build(int *board, int index)//Checked before calling build() if you are not moving/if you are winning
{
	if (is_player(board[index]) == 1)
		error("Occupied");
	else if (is_dome(board[index]) == 1)
		error ("Dome");
	else
	{
		//check if player and building place are next to each other
		board[index] = board[index] + 1;
		return (1);
	}
	return (0);
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
//		printf("%d, ", board[i]);
		i++;
	}
//	printf("\n");

//	move();
	board[3] = 10;
	ft_build(board, 3);
	printf("Value after building in empty square is %d\n", board[3]);
	ft_build(board, 3);
	printf("Value after building in empty square is %d\n", board[3]);
	ft_build(board, 3);
	printf("Value after building in empty square is %d\n", board[3]);

	i  = 0;
	while (i < 25)
	{
		printf("%d, ", board[i]);
		i++;
	}
	printf("\n");

	ft_build(board, 3);
	printf("Value after building in empty square is %d\n", board[3]);
	ft_build(board, 3);
	printf("Value after building in empty square is %d\n", board[3]);
	return (0);
}
