/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:58:46 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/17 22:55:25 by spuustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santorini.h"

static int	check_delim(char *str, int i)
{
	if (str[i] && str[i] != ' ')
		return (error("delimiter"));
	return (2);
}

void	print_state(int *array)
{
	ft_putstr("tulostan stagen\n");
	int i = 0;
	int y = 0;
	int x;
	
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			ft_putnbr(array[i]);
			i++;
			ft_putchar(' ');
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}


void	set_empty_stage(int *array)
{
	int i = 0;
	char pos[2];
	char plr = 'A';
	int	c = 10;
	ft_putstr("asetan tyhjan stagen.\n");
	while (i < 25)
	{
		array[i] = 0;
		i++;
	}
	i = 0;
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

int		set_stage(int *array, char *buffer)
{
	ft_putstr("asetan stagen\n");
	int i = 1;
	int	count;
	int	square;
	int player_placed[4] = {0,0,0,0};
	
	while (buffer[i] != '\0' && i + 1 != ft_strlen(buffer))
	{
		if (buffer[i] && buffer[i] != ' ')
		{
			ft_putstr("delim is:");
			ft_putchar(buffer[i]);
			return (error("delimiter"));
		}
		i++;
		square = ft_atoi(buffer + i);
		if (square < 1 || square > 25)
		{
			ft_putstr("bad index\n");
			return (0); //error
		}
		i += ft_num_length(square);
		if (buffer[i] != '.')
		{
			ft_putstr("no point\n");
			return (0); //error
		}
		i++;
		if (buffer[i] >= '1' && buffer[i] <= '4')
			array[square] = buffer[i];
		else if (buffer[i] == 'A' && player_placed[0] == 0)
		{
			array[square - 1] += 10;
			player_placed[0] = 1;
		} else if (buffer[i] == 'B' && player_placed[1] == 0)
		{
			array[square - 1] += 20;
			player_placed[1] = 1;
		} else if (buffer[i] == 'C' && player_placed[2] == 0)
		{
			array[square - 1] += 30;
			player_placed[2] = 1;
		} else if (buffer[i] == 'D' && player_placed[3] == 0)
		{
			array[square - 1] += 40;
			player_placed[3] = 1;
		}
		else
		{
			ft_putstr("bad fill\n");
			return (0); //error
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (player_placed[i] == 0)
		{
			ft_putstr("player not placed\n");
			return(0);
		}
		i++;
	}
	return (0);
}		

