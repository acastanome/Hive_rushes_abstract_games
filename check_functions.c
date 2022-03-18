/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:31:02 by acastano          #+#    #+#             */
/*   Updated: 2022/03/18 17:38:31 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "santorini.h"
#include <stdio.h>//test

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
	{
		printf("wrong player id\n");
		return (0);
	}
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
//	if ((dif == -6) || (dif == 6) || (dif == -5) || (dif == 5) || (dif == -1) || (dif == 1))
//		return (1);
	printf("in adjacent dif is %d and pos1+1 mod5 is %d\n", dif, ((pos1+1) % 5));
	if (pos1 < pos2)
	{
		if ((((pos1 + 1) % 5) == 0) && ((dif == 4) || (dif == 5)))
//		{
//			printf("we here?");
			return (1);
//		}
		else if (((pos1 % 5) == 0) && ((dif == 1) || (dif == 5) || (dif == 6)))
			return (1);
		else if ((dif == 1) || (dif == 4) || (dif == 5) || (dif == 6))
			return (1);
	}
	if (pos1 > pos2)
	{
		if ((((pos1 + 1) % 5) == 0) && ((dif == -1) || (dif == -5) || (dif == -6)))
		{
			printf("we here?1");
			return (1);
		}
		else if (((pos1 % 5) == 0) && ((dif == -4) || (dif == -5)))
		{
			printf("we here?2");
			return (1);
		}
		else if (((pos1 % 5) != 0) && ((dif == -1) || (dif == -4) || (dif == -5) || (dif == -6)))
		{
			printf("we here?3");
			return (1);
		}
	}
	return (ret);
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
	if (height_difference(pos1, pos2) > 1)
		return (0);
	return (1);
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
	if (is_player(position) == 1)
	{
		printf("\tPOS\n");
		return (0);
	}
	if (is_dome(position) == 1)
	{
		printf("\tDOME\n");
		return (0);
	}
	return (1);
}
