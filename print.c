/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:20:43 by spuustin          #+#    #+#             */
/*   Updated: 2022/03/18 22:04:19 by spuustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santorini.h"

void	print_board(int *array)
{
	ft_putstr("printing current state.\n");
	int i = 0;
	int y = 0;
	int x;
	
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			if (array[i] >=40)
			{
				ft_putchar('D');
				if (array[i] > 40)
					ft_putnbr(array[i] - 40);
			}
			else if (array[i] >=30)
			{
				ft_putchar('C');
				if (array[i] > 30)
					ft_putnbr(array[i] - 30);
			}
			else if (array[i] >=20)
			{
				ft_putchar('B');
				if (array[i] > 20)
					ft_putnbr(array[i] - 20);
			}
			else if (array[i] >=10)
			{
				ft_putchar('A');
				if (array[i] > 10)
					ft_putnbr(array[i] - 10);
			}
			else
				ft_putnbr(array[i]);
			i++;
			ft_putchar(' ');
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}