/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   santorini.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:22:23 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/17 23:07:52 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

//error.c
int error(char *str);

//check_functions
int	is_player(int square_status);
int	is_player_id(int square_status, int player_id);
int	is_adjacent(int pos1, int pos2);
int	height_difference(int pos1, int pos2);
int	is_level_ok(int pos1, int pos2);
int	is_dome(int square_status);
int	is_position_buildable(int position);

//board.c
int	ft_move(int *board, int player_id, int pos1, int pos2);
int	ft_build(int *board, int player_position, int position);

#endif
