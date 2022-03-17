/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:34:30 by acastano          #+#    #+#             */
/*   Updated: 2022/03/17 21:20:40 by acastano         ###   ########.fr       */
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
int	is_player_id(int square_status, int player_id)
{
	if ((square_status / 10) == player_id)
		return (1);
	return (0);
}

//-------------------------------------------------------------------------
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
/*
 * is_adjacent() takes an int array representing the board (and it's content),
 * an int representing the index of position 1, and an int representing the index
 * of the position 2.
 * It checks if the positions are adjacent.
 * Return values: 1 if they are, 0 if not.
 */
int	is_adjacent(int *map, int pos1, int pos2)
{
	if ((square_status / 10) == player_id)//not done
		return (1);
	return (0);
}

/*
 * height_difference() takes two int representing the index of two positions.
 * It calculates the difference in heights, taking into account there is a player
 * in pos1.
 * Return values: An int greater than, equal to, or less than 0, depending is the
 * height of pos1 greater than, equal to, or less than the height of pos2.
 */
int	height_difference(int pos1, int pos2)
{
	return ((pos1 % 10) - pos2);
}

/*
 * is_level_ok() takes an int representing the index of the position to move from,
 * and an int representing the index of the position to move to.
 * It checks if the difference in heights is according to the rules.
 * Return values: 1 if they are, 0 if not.
 */
int	is_level_ok(int pos1, int pos2)
{
	if ((square_status / 10) == player_id)//not done
		return (1);
	return (0);
}

/*
 * ft_move() takes an int array representing the board (and it's content), an
 * int representing the player_id, an int representing the index of square we want
 * to move from, and an int representing the index of square we want to move to.
 * Return values: Calls error and returns 0 if failed, 1 if it moves.
 */
int	ft_move(int *map, int player_id, int pos1, int pos2)
{
	if (is_player_id(map[pos1], player_id) == 0)
	{
		error("Player not there");
		return (0);
	}
	if (is_position_buildable(map[pos2]) == 0)
	{
		error("Occupied");
		return (0);
	}
	if (is_adjacent(map, pos1, pos2) == 0)
	{
		error("Not adjacent");
		return (0);
	}
	if (is_level_ok(pos1, pos2) == 0)
	{
		error("Level height");
		return (0);
	}
	map[pos1] = map[pos1] - player_id;
	map[pos2] = map[pos2] + player_id;
	return (1);
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
 * is_position_free() checks if there is already a player or a dome in that square.
 * Return values: 1 if there is something, 0 if not.
 */
int	is_position_buildable(int *map, int position)
{
	if ((is_player(map[position]) == 1) || (is_dome(map[position]) == 1))
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
	if (is_position_buildable(board[index]) == 0)
	{
		error ("Occupied");
		return (0);
	}
	//check if player and building place are next to each other
	board[index] = board[index] + 1;
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
