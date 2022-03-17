/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:25:38 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/17 21:31:38 by spuustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "santorini.h"

static int	check_delim(char *str, int i)
{
	if (str[i] && str[i] != ' ')
		return (error("delimiter"));
	return (2);
}

static int	turn_parser(char *str)
{
	int		player;
	int		move_from;
	int		move_to;
	int		build;
	int		i = 1;

	if (str[i] && str[i] != ' ')
		return (error("delimiter"));
	i++;
	if (str[i] && (str[i] == 'A' || str[i] == 'B' || str[i] == 'C' || str[i] == 'D'))
		player = str[i];
	else
		return (error("player"));
	i++;
	//move_from
	if (str[i] && str[i] != ' ')
		return (error("delimiter"));
	i++;
	move_to = ft_atoi(str + i);
	if (move_to < 0 || move_to > 25)
		return (error("move"));
	i += ft_num_length(move_to);
	if (str[i] && str[i] != ' ')
		return (error("delimiter"));
	i++;
	build = ft_atoi(str + i);
	if (build < 0 || build > 25)
		return (error("build"));
	i += ft_num_length(build);
	i++;
	if (i != ft_strlen(str))
		return (error("strlen"));
	//function call
	//function(player, move_from, move_to, build);
	return (0);
}

int		main(void)
{
	char buffer[1000];
	int ret = 2;
	int e = 1;
	int array[25];
	int i = 0;
	while (i < 25)
	{
		(array[i] = 0);
		i++;
	}
	while (e != 0)
	{
		ret = read(STDIN_FILENO, buffer, 1000);
		if (buffer[0] == 'T')
			e = turn_parser(buffer);
		else if (buffer[0] == 'E')
			set_empty_stage(array);
		else if (buffer[0] == 'P')
			print_state(array);
		else if (buffer[0] == 'S')
			set_stage(array, buffer);
	}
	return (0);
}