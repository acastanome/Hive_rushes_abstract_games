/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:31:02 by acastano          #+#    #+#             */
/*   Updated: 2022/03/18 23:21:04 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "santorini.h"

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
 * is_player_id() checks if there is the right player in that square
 * Return values: 1 if there is the correct player, 0 if not.
 */
int	is_player_id(int square_status, int player_id)
{
	if ((square_status / 10) != (player_id / 10))
		return (0);
	return (1);
}

/*
 * is_adjacent() takes an int representing the index of position 1, and an int
 * representing the index of the position 2.
 * It checks if the positions are adjacent: Top, bottom, left, right and diagonals.
 * Return values: 1 if they are, 0 if not.
 */
int	is_adjacent(int pos1, int pos2)
{
	int	dif;
	int	ret;

	ret = 0;
	dif = pos2 - pos1;
	if (pos1 < pos2)
	{
		if ((((pos1 + 1) % 5) == 0) && ((dif == 4) || (dif == 5)))
			return (1);
		else if (((pos1 % 5) == 0) && ((dif == 1) || (dif == 5) || (dif == 6)))
			return (1);
		else if (((pos1 % 5) != 0) && ((dif == 1) || (dif == 4) || (dif == 5) || (dif == 6)))
			return (1);
	}
	if (pos1 > pos2)
	{
		if ((((pos1 + 1) % 5) == 0) && ((dif == -1) || (dif == -5) || (dif == -6)))
			return (1);
		else if (((pos1 % 5) == 0) && ((dif == -4) || (dif == -5)))
			return (1);
		else if (((pos1 % 5) != 0) && ((dif == -1) || (dif == -4) || (dif == -5) || (dif == -6)))
			return (1);
	}
	return (ret);
}

/*
 * is_level_ok() takes an int representing the index of the position to move from,
 * and an int representing the index of the position to move to.
 * It checks if the difference in heights is according to the rules.
 * Return values: 1 if they are, 0 if not.
 */
int	is_level_ok(int pos1, int pos2)
{
	if ((pos1 == pos2) || (pos1 > pos2))
		return (1);
	if ((pos2 - pos1) == 1)
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
int	is_position_buildable(int position)
{
	if ((is_player(position) == 1) || (is_dome(position) == 1))
		return (0);
	return (1);
}
