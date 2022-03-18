/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:58:46 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/18 12:30:39 by spuustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santorini.h"

static int	check_delim(char *str, int i)
{
	if (str[i] && str[i] != ' ')
		return (error("delimiter"));
	return (2);
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
	ft_putstr("setting up an empty state.\n");
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

static int	is_populated(int *array, int index)
{
	if (array[index - 1] > 9)
	{
		ft_putstr("square already populated.\n");
		return (1);
	}
	return (0);
}
static int	builder_set(int *plrs, char p)
{
	if (p == 'A' && plrs[0] == 1)
	{
		ft_putstr("builder already placed elsewhere.\n");
		return (1);
	}
	if (p == 'B' && plrs[1] == 1)
	{
		ft_putstr("builder already placed elsewhere.\n");
		return (1);
	}
	if (p == 'C' && plrs[2] == 1)
	{
		ft_putstr("builder already placed elsewhere.\n");
		return (1);
	}
	if (p == 'D' && plrs[3] == 1)
	{
		ft_putstr("builder already placed elsewhere.\n");
		return (1);
	}
	return (0);
		
}
int		set_stage(int *array, char *buffer)
{
	int i = 1;
	int	count;
	int	square;
	int builders[4] = {0,0,0,0};
	
	while (buffer[i] != '\0' && i + 1 != ft_strlen(buffer))
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
			return (0); //error
		}
		i += ft_num_length(square);
		if (buffer[i] != '.')
		{
			set_empty_stage(array);
			ft_putstr("no point as delimiter\n");
			return (0); //error
		}
		i++;
		if (buffer[i] >= '1' && buffer[i] <= '4')
			array[square] = buffer[i];
		else if (buffer[i] == 'A')
		{
			if (builder_set(builders, 'A') == 1)
				return (0);
			if (is_populated(array, square) == 1)
				return(0);
			else
			{
				array[square - 1] += 10;
				builders[0] = 1;
			}
		} 
		else if (buffer[i] == 'B')
		{
			if (builder_set(builders, 'B') == 1)
				return (0);
			if (is_populated(array, square) == 1)
				return(0);
			else
			{
				array[square - 1] += 20;
				builders[1] = 1;
			}
		} 
				else if (buffer[i] == 'C')
		{
			if (builder_set(builders, 'C') == 1)
				return (0);
			if (is_populated(array, square) == 1)
				return(0);
			else
			{
				array[square - 1] += 30;
				builders[2] = 1;
			}
		} 
				else if (buffer[i] == 'D')
		{
			if (builder_set(builders, 'D') == 1)
				return (0);
			if (is_populated(array, square) == 1)
				return(0);
			else
			{
				array[square - 1] += 40;
				builders[3] = 1;
			}
		} 
		else
		{
			set_empty_stage(array);
			ft_putstr("insert a block-height (1-4) or a player (A-D).\n");
			return (0); //error
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
