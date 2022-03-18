/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   santorini.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:22:23 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/18 23:22:53 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <unistd.h>
#include "libft/libft.h"

//error.c
int error(char *str);

//board.c
int	ft_play(int *board, int player_id, int i_move_from, int i_move_to, int i_build);
int	ft_move(int *board, int player_id, int pos1, int pos2);
int	ft_build(int *board, int player_position, int position);

//check_functions
int	is_player_id(int square_status, int player_id);
int	is_player(int square_status);
int	is_position_buildable(int position);
int	is_adjacent(int pos1, int pos2);
int	is_level_ok(int pos1, int pos2);
int	is_dome(int square_status);

//print
void	print_state(int *array);

//state
int		set_stage(int *array, char *buffer);
void	set_empty_stage(int *array);

//turn
int		turn_parser(char *str, int *array);
int		is_char(char *str, int i, char c);

//start
int	new_game(int *array, char *str, int turn);
#endif
