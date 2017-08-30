/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_reduced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 17:19:51 by esterna           #+#    #+#             */
/*   Updated: 2017/08/29 21:22:30 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int			check_coeff(double **coeff, int power)
{
	int i;

	i = 0;
	while (coeff[0][i] == coeff[1][i] && i <= power)
		i++;
	if (i == power + 1)
		return (0);
	return (1);
}

double		**reduce_coeff(double **ptr, int *power)
{
	int i;

	i = 0;
	while (i <= *power)
	{
		ptr[0][i] = ptr[0][i] - ptr[1][i];
		i++;
	}
	i = *power;
	while (ptr[0][i] == 0 && i >= 0)
		i--;
	*power = i;
	return (ptr);
}

void		print_x(double **coeff, int i, int neg)
{
	ft_printf("%g", coeff[0][i] * neg);
	if (i == 1)
		ft_printf(" * X", coeff[0][i] * neg);
	else if (i > 1)
		ft_printf(" * X^%d", coeff[0][i] * neg, i);
}

/*
** Finds the reduced form of the polynomial and prints it.
*/

double		**print_reduced(double **ptr, int *power)
{
	int		i;
	double	neg;

	neg = 1.0;
	if (check_coeff(ptr, *power) == 0 && ft_printf("0 = 0\n"))
		return (ptr);
	ptr = reduce_coeff(ptr, power);
	i = 0;
	while (i <= *power)
	{
		if (ptr[0][i] != 0)
		{
			print_x(ptr, i, neg);
			if (++i <= *power && ptr[0][i] != 0)
			{
				ft_printf(" %c ", (ptr[0][i] > 0 ? '+' : '-'));
				neg = (ptr[0][i] > 0) ? 1.0 : -1.0;
			}
		}
		else if (++i <= *power && ptr[0][i] < 0 && (neg = -1.0))
			ft_putstr(" - ");
	}
	ft_putstr(" = 0\n");
	return (ptr);
}
