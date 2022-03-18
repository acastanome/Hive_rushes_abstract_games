/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:29:20 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/18 21:49:36 by spuustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santorini.h"
#include <stdio.h>

static int has_room(int *array, int pos, int pid)
{
	int i = 0;
	while (i < 25)
	{
		if (is_adjacent(pos, i) == 1)
			if (is_position_buildable(array[i]) == 1)
				if (is_level_ok((array[i] - pid), array[i]) == 1)
					return (1);
		i++;
	}
	return (0);
}
int get_pid(int value)
{
	if (value > 39)
		return (40);
	else if (value > 29)
		return (30);
	else if (value > 19)
		return (20);
	else
		return (10);
}

int can_plr_move(int *array, int player)
{
	int i = 0;
	int lowerb = 10;
	int	upperb = 25;
	int	pos_1 = 0;
	int	pos_2 = 0;
	int ret;
	int pid;
	if (player == 2)
	{
		upperb *= 2;
		lowerb *= 3;
	}
	while (i < 25)
	{
		while (pos_1 == 0)
		{
			if (array[i] >= lowerb && array[i] < upperb)
				pos_1 = i;
			i++;
		}
		while (pos_2 == 0)
		{
			if (array[i] >= lowerb && array[i] < upperb)
				pos_2 = i;
			i++;
		}
		i++;
	}
	pid = get_pid(array[pos_1]);
	ret = has_room(array, pos_1, pid);
	if (ret == 0)
	{
		pid = get_pid(array[pos_2]);
		ret = has_room(array, pos_2, pid);
	}
	return (ret);
}
