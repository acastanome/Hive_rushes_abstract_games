/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:34:30 by acastano          #+#    #+#             */
/*   Updated: 2022/03/18 23:21:46 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "santorini.h"

/*
 * ft_move() takes an int array representing the board (and it's content), an
 * int representing the player_id, an int representing the index of square we want
 * to move from, and an int representing the index of square we want to move to.
 * Return values: Calls error and returns 0 if failed, 1 if it moves.
 */
int	ft_move(int *board, int player_id, int pos1, int pos2)
{
	if (is_player_id(board[pos1], player_id) == 0)
		error("Player not there");
	else if (is_position_buildable(board[pos2]) == 0)
		error("Occupied");
	else if (is_adjacent(pos1, pos2) == 0)
		error("Not adjacent");
	else if (is_level_ok((board[pos1] - player_id), board[pos2]) == 0)
		error("Level height");
	else
	{
		board[pos1] = (board[pos1] - player_id);
		board[pos2] = (board[pos2] + player_id);
		return (1);
	}
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
	if (is_adjacent(player_position, position) == 0)
		error("Not adjacent");
	else if (is_position_buildable(board[position]) == 0)
		error ("Occupied");
	else
	{
		board[position] = board[position] + 1;
		return (1);
	}
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
	if ((ft_move(temp_board, player_id, i_move_from, i_move_to) == 1)
		&& (ft_build(temp_board, i_move_to, i_build) == 1))
	{
		i = 0;
		while (i < 25)
		{
			board[i] = temp_board[i];
			i++;
			}
		return (1);
	}
	return (0);
}
