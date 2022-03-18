/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:29:20 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/19 00:36:00 by spuustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santorini.h"
#include <stdio.h>
#include <stdlib.h>

static int has_room(int *array, int pos, int pid)
{
	int i = 0;
	while (i < 25)
	{
		if (is_adjacent(pos, i) == 1)
			if (is_position_buildable(array[i]) == 1)
				if (is_level_ok((array[pos] - pid), array[i]) == 1)
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
	else if (value > 9)
		return (10);
	return (0);
}

int can_plr_move(int *array, int player)
{
	int i = 0;
	int lowerb = 9;
	int	upperb = 23;
	int	pos_1 = -10;
	int	pos_2 = -10;
	int ret;
	int pid;
	if (player == 2)
	{
		upperb = 43;
		lowerb = 29;
	}
	while (i < 25)
	{
		while (pos_1 == -10)
		{
			if (array[i] >= lowerb && array[i] <= upperb)
				pos_1 = i;
			i++;
		}
		while (pos_2 == -10)
		{
			if (array[i] >= lowerb && array[i] <= upperb)
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
	if (ret == 0)
	{
		ft_putstr("player ");
		ft_putnbr(player);
		ft_putstr(", you cant move anywhere, you lost the game.\n");
		exit(-1);
	}
	return (1);
}
