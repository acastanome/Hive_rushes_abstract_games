/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:00:46 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/17 16:39:01 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "santorini.h"

int		error(char *str)
{
	if (ft_strcmp(str, "delimiter") == 0)
		ft_putstr("wrong delimiter, needs to be a space(' '), please try again.\n");
	if (ft_strcmp(str, "player") == 0)
		ft_putstr("invalid player, needs to be A,B,C or D, please try again.\n");
	if (ft_strcmp(str, "move") == 0)
		ft_putstr("the square you are trying to move to needs to be between 1-25.\n");
	if (ft_strcmp(str, "build") == 0)
		ft_putstr("the square you are trying to build on needs to be between 1-25, please try again.\n");
	if (ft_strcmp(str, "strlen") == 0)
		ft_putstr("your string must be in correct form, please try again.\n");
	if (ft_strcmp(str, "Occupied") == 0)
		ft_putstr("Can't build in that square, there is a player! What do you want to do instead?\n");
	if (ft_strcmp(str, "Dome") == 0)
		ft_putstr("Can't keep building here, there is a dome! What do you want to do instead?\n");
	return (1);
}