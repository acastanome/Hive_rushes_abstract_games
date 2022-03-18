/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:08:18 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/19 01:13:35 by spuustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santorini.h"

int err(int *array)
{
	set_empty_stage(array);
	ft_putstr("error\n");
	return (0);
}

int	new_game(int *array, char *str, int turn)
{
	int i = 1;
	int j = 0;
	int k = 0;
	char plr;
	int sqr;
	if (turn == 2)
		k = 2;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ')
			return (err(array));
		i++;
		if (str[i] != ('A' + j + k))
			return (err(array));
		plr = str[i];
		i++;
		if (str[i] != ' ')
			return (err(array));
		sqr = ft_atoi(str + i);
		if (sqr > 25 || sqr < 1)
			return (err(array));
		if (array[sqr - 1] != 0)
			return (err(array));
		array[sqr - 1] = 10 * (1 + plr - 'A');
		i+= ft_num_length(sqr);
		i++;
		j++;
	}
	if (j != 2)
		return (err(array));
	return (1);
}