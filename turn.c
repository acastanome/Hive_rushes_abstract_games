/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:39:27 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/18 16:56:53 by spuustin         ###   ########.fr       */
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
	char 	s = ' ';

	if (is_char(str, i, ' ') == 0)
		return (error("delimiter"));
	i++;
	if (str[i] && (str[i] == 'A' || str[i] == 'B' || str[i] == 'C' || str[i] == 'D'))
		player = player_char_to_id(str[i]);
	else
		return (error("player"));
	i++;
	if (is_char(str, i, ' ') == 0)
		return (error("delimiter"));
	i++;
	move_from = ft_atoi(str + i);
	if (move_from < 1 || move_from > 25)
		return (0); //error(from)
	i += ft_num_length(move_from);
	if (is_char(str, i, ' ') == 0)
		return (error("delimiter"));
	i++;
	move_to = ft_atoi(str + i);
	if (move_to < 1 || move_to > 25)
		return (error("move"));
	if (move_from == move_to)
		return(0); //you cant move to where you are at!
	i += ft_num_length(move_to);
	if (is_char(str, i, ' ') == 0)
		return (error("delimiter"));
	i++;
	build = ft_atoi(str + i);
	if (build < 1 || build > 25)
		return (error("build"));
	if (build == move_to)
		return (0); //you cant build on where you currently are!
	i += ft_num_length(build);
	i++;
	if (i != ft_strlen(str))
		return (error("strlen"));
	ft_putstr("player: ");
	ft_putnbr(player);
	ft_putstr(", from: ");
	ft_putnbr(move_from);
	ft_putstr(", to: ");
	ft_putnbr(move_to);
	ft_putstr(", build on: ");
	ft_putnbr(build);
	ft_putchar('\n');
	//function(array, player, move_from -1, move_to -1, build -1);
	return (0);
}
