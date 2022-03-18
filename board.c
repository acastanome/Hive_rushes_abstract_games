/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:34:30 by acastano          #+#    #+#             */
/*   Updated: 2022/03/18 17:39:07 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "santorini.h"
#include <stdio.h>

/*
 * ft_move() takes an int array representing the board (and it's content), an
 * int representing the player_id, an int representing the index of square we want
 * to move from, and an int representing the index of square we want to move to.
 * Return values: Calls error and returns 0 if failed, 1 if it moves.
 */
int	ft_move(int *board, int player_id, int pos1, int pos2)
{
	int	i;

	printf("in ft_move()\n");
	if (is_player_id(board[pos1], player_id) == 0)
	{
		error("Player not there");
		printf("\tft_move() after player not there\n");
	}
	else if (is_position_buildable(board[pos2]) == 0)
	{
		error("Occupied");
		printf("\tft_move() after occ\n");
	}
	else if (is_adjacent(pos1, pos2) == 0)
	{	
		error("Not adjacent");
		printf("\tft_move() not adj: pos1 is %d, pos2 is %d\n", pos1, pos2);
	}
	else if (is_level_ok(pos1, pos2) == 0)
	{
		error("Level height");
		printf("\tft_move() level heigh\n");
	}
	else
	{
		printf("\tft_move() in loop\n");
		board[pos1] = (board[pos1] - player_id);
		board[pos2] = (board[pos2] + player_id);
		i = 0;
		while (i < 25)
		{
			printf("%d ",board[i]);
			if ((((i + 1) % 5) == 0) && 1 != 0)
				printf("\n");
			i++;
		}
		return (1);
	}
	printf("\tft_move() failed\n");
	return (0);
}

/*
 * ft_build() takes an int array representing the board (and it's content),
 * an int representing the index where the character was moved to, and
 * an int representing the index of the square we want to build in.
 * Checks if the player is next to the square you want to build in,
 * and if that square is buildable. If so, it builds there.
 * Return values: Returns 0 (and calls error) if failed, 1 if it builds.
 */
int	ft_build(int *board, int player_position, int position)
{
	int	i;

	printf("in ft_build()\n");
	if (is_adjacent(player_position, position) == 0)
		error("Not adjacent");
	else if (is_position_buildable(board[position]) == 0)
		error ("Occupied");
	else
	{
		board[position] = board[position] + 1;
		i = 0;
		while (i < 25)
		{
			printf("%d ",board[i]);
			if ((((i + 1) % 5) == 0) && 1 != 0)
				printf("\n");
			i++;
		}
		return (1);
	}
	printf("\tft_build() failed\n");
	return (0);
}

/*
 * ft_play() takes an int array representing the board (and it's content),
 * an int representing the player_id, and three int for the indexes where the character
 * wants to move from,  move to, and the square to build in.
 * Calls functions ft_move() and ft_build() to do their namesake actions, and updates the
 * board upon success.
 * Return values: Returns 1 upon success, 0 otherwise.
 */
int	ft_play(int *board, int player_id, int i_move_from, int i_move_to, int i_build)
{
	int	temp_board[25];
	int	i;

	i = 0;
	while (i < 25)
	{
		temp_board[i] = board[i];
		i++;
	}
	printf("in ft_play()\n");
	if ((ft_move(temp_board, player_id, i_move_from, i_move_to) == 1)
		&& (ft_build(temp_board, i_move_to, i_build) == 1))
	{
		printf("\tft_play() move and build are true\n");
		i = 0;
		while (i < 25)
		{
			board[i] = temp_board[i];
			i++;
		}
		return (1);
	}
	printf("ft_play() failed\n");
	return (0);
	//print_map(map);
	//ask_next_move;
}

int	main(void)
{
	int	board[25];
	int	i;

	i = 0;
	while (i < 25)
	{
		board[i] = 0;
		i++;
	}
	board[3] = 1;
	board[5] = 31;
	board[7] = 1;
	board[8] = 1;
	board[9] = 1;
	i = 0;
	while (i < 25)
	{
		printf("%d ",board[i]);
		if ((((i + 1) % 5) == 0) && 1 != 0)
			printf("\n");
		i++;
	}
//	ft_play(board, 30, 4, 5, 6);
	ft_play(board, 30, 5, 1, 2);
	printf("\n");
	i = 0;
	while (i < 25)
	{
		printf("%d ",board[i]);
		if ((((i + 1) % 5) == 0) && 1 != 0)
			printf("\n");
		i++;
	}
	return (0);
}
