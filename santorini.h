/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   santorini.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:22:23 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/17 19:39:12 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

//error.c
int error(char *str);

//board.c
int	is_player_id(int square_status, int player);
int	ft_move(int *map, int player, int pos1, int pos2);
int	is_player(int square_status);
int	is_dome(int square_status);
int	ft_build(int *board, int index);

#endif
