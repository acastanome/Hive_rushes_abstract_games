/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:39:27 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/19 00:16:09 by spuustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "santorini.h"

int	is_char(char *str, int i, char c)
{
	if (str[i] && str[i] != c)
		return (0);
	return (2);
}
int static	player_char_to_id(char c)
{
	if (c == 'A')
		return (10);
	if (c == 'B')
		return (20);
	if (c == 'C')
		return (30);
	return (40);
}
int	turn_parser(char *str, int *array)
{
	int		player;
	int		move_from;
	int		move_to;
	int		build;
	int		i = 1;
	int		p = 1;

	if (is_char(str, i, ' ') == 0)
		return (error("delimiter"));
	i++;
	if (str[i] && (str[i] == 'A' || str[i] == 'B' || str[i] == 'C' || str[i] == 'D'))
		player = player_char_to_id(str[i]);
	else
		return (error("player"));
	if (player == 30 || player == 40)
		p = 2;
	can_plr_move(array, p);
	i++;
	if (is_char(str, i, ' ') == 0)
		return (error("delimiter"));
	i++;
	move_from = ft_atoi(str + i);
	if (move_from < 1 || move_from > 25)
	{
		ft_putstr("you arent on that square!!\n");
		return (1);
	}
	i += ft_num_length(move_from);
	if (is_char(str, i, ' ') == 0)
		return (error("delimiter"));
	i++;
	move_to = ft_atoi(str + i);
	if (move_to < 1 || move_to > 25)
		return (error("move"));
	if (move_from == move_to)
	{
		ft_putstr("you cant move to the square you are currently on!\n");
		return (1);
	}
	i += ft_num_length(move_to);
	if (is_char(str, i, ' ') == 0)
		return (error("delimiter"));
	i++;
	build = ft_atoi(str + i);
	if (build < 1 || build > 25)
		return (error("build"));
	if (build == move_to)
	{
		ft_putstr("you cant build on top of yourself!\n");
		return (1);
	}
	i += ft_num_length(build);
	i++;
	if (i != (int) ft_strlen(str))
		return (error("strlen"));
	ft_play(array, player, move_from -1, move_to -1, build -1);
	return (0);
}
