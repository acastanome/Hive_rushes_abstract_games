/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:58:46 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/19 01:14:45 by spuustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santorini.h"

int is_game_won(int *array)
{
	int i = 0;
	while (i < 25)
	{
		if (array[i] == 13 || array[i] == 23 || \
		array[i] == 33 || array[i] == 43)
		{
			ft_putstr("the game you set is already won, try again.\n");
			set_empty_stage(array);
			return (1);
		}
		i++;
	}
	return (0);
}
void print_player_on_build(int index, int value)
{
	int pid;
	
	if (value % 10 != 0)
	{
		ft_putnbr(index + 1);
		ft_putchar('.');
		ft_putnbr(value % 10);
		ft_putchar(' ');
	}
	if (value > 9)
	{
		pid = get_pid(value);
		ft_putnbr(index + 1);
		ft_putchar('.');
		if (pid == 40)
			ft_putchar('D');
		if (pid == 30)
			ft_putchar('C');
		if (pid == 20)
			ft_putchar('B');
		if (pid == 10)
			ft_putchar('A');
		ft_putchar(' ');
	}
}

void print_state(int *array)
{
	int i = 0;
	
	while (i < 25)
	{
		if (array[i] == 0)
			i++;
		else
		{
			print_player_on_build(i, array[i]);
			i++;
			while (array[i] == 0 && i < 25)
			{
				i++;
			}
		}
	}
	ft_putchar('\n');
}

void	populate(int *array)
{
	char pos[2];
	int i = 0;
	char plr = 'A';
	int c = 10;
	while (i < 4)
	{
		ft_putstr("give a position of a builder ");
		ft_putchar(plr);
		plr++;
		ft_putchar('\n');
		read(STDIN_FILENO, pos, 2);
		array[ft_atoi(pos) - 1] = c;
		c += 10;
		i++;
	}
}

void	set_empty_stage(int *array)
{
	int i = 0;
	while (i < 25)
	{
		array[i] = 0;
		i++;
	}
}

int		delim_count(char *array, char delim)
{
	int count = 0;
	int i = 0;
	while (array[i] != '\0')
	{
		if (array[i] == delim && array[i + 1] && array[i + 1] != delim && array[i + 2])
			count ++;
		i++;
	}
	return (count);
}

static int	is_square_populated(int *array, int index)
{
	if (array[index] > 9)
	{
		ft_putstr("square already populated.\n");
		return (1);
	}
	return (0);
}

static int		is_builder_placed(char plr, int *placed)
{
	int	i = plr - 'A';
	if (placed[i] == 1)
	{
		ft_putstr("player already placed.\n");
		return (1);
	}
	return (0);
}

static void	populate_builder(int *array, int i, int *builders, char plr)
{
	int p = plr - 'A';
	
	builders[p] = 1;
	while (p >= 0)
	{
		array[i] += 10;
		p--;
	}
}

int		set_stage(int *array, char *buffer)
{
	int i = 1;
	int	square;
	int builders[4] = {0,0,0,0};
	
	while (buffer[i] != '\n')
	{
		if (is_char(buffer, i, ' ') == 0)
		{
			set_empty_stage(array);
			return (error("delimiter"));
		}
		i++;
		square = ft_atoi(buffer + i);
		if (square < 1 || square > 25)
		{
			set_empty_stage(array);
			ft_putstr("square number needs to be 1-25\n");
			return (0); 
		}
		i += ft_num_length(square);
		if (buffer[i] != '.')
		{
			set_empty_stage(array);
			ft_putstr("no point as delimiter\n");
			return (0); 
		}
		i++;
		if (buffer[i] >= 'A' && buffer[i] <= 'D')
		{
			if (is_builder_placed(buffer[i], builders) == 1 || \
			is_square_populated(array, square - 1) == 1)
			{
				set_empty_stage(array);
				return (0);
			}
			populate_builder(array, square - 1, builders, buffer[i]);
		}
		else if (buffer[i] >= '1' && buffer[i] <= '5')
		{
			array[square - 1] += ft_atoi(buffer + i);
		}
		else
		{
			set_empty_stage(array);
			ft_putstr("insert a block-height (1-4) or a player (A-D).\n");
			return (0); 
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (builders[i] == 0)
		{
			set_empty_stage(array);
			ft_putstr("all players need to be placed.\n");
			return(0);
		}
		i++;
	}
	return (0);
}		

