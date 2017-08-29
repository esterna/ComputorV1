/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coeffs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:47:00 by esterna           #+#    #+#             */
/*   Updated: 2017/08/29 15:49:25 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

/*
** Used to find the polynomial equation's power.
*/

int			find_power(char *str)
{
	int		l;
	int		r;
	int		equ;

	l = 0;
	r = 0;
	equ = 0;
	while (*str)
	{
		if ((*str == 'x' || *str == 'X') && *(str + 1) != '^')
		{
			if (equ == 0 && l == 0)
				l = 1;
			else if (equ == 1 && r == 0)
				r = 1;
		}
		if (*str == '=')
			equ = 1;
		if (*str == '^')
		{
			str++;
			if (*str - '0' > l && !equ)
				l = *str - '0';
			else if (*str - '0' > r && equ)
				r = *str - '0';
		}
		str++;
	}
	if (l > r)
		return (l);
	else
		return (r);
}

/*
** Finds the coeffiecients of all the powers and sorts them,
** for both the left and right of the equation.
*/

double		**find_coeff(char *str)
{
	int		side;
	int		neg;
	double	tmp;
	double	**coeff;

	side = find_power(str) + 1;
	coeff = (double **)malloc(sizeof(double *) * 2);
	coeff[0] = (double *)malloc(sizeof(double) * side);
	coeff[1] = (double *)malloc(sizeof(double) * side);
	ft_bzero(coeff[0], sizeof(double) * side);
	ft_bzero(coeff[1], sizeof(double) * side);
	side = 0;
	while (*str != '\0')
	{
		while (ft_isspace(*str) != 0)
			str++;
		if (*str == '=')
		{
			side++;
			str++;
		}
		neg = (*str == '-') ? -1 : 1;
		while (ft_isdigit(*str) == 0 && *str != 'x' &&
				*str != 'X' && *str != '\0')
			str++;
		tmp = (*str == 'x' || *str == 'X') ? 1 : neg * ft_atod(str);
		while ((ft_isdigit(*str) == 1 || *str == '.' ||
					ft_isspace(*str) == 1 || *str == '*') && *str != '\0')
			str++;
		if (*str == '+' || *str == '-' || *str == '=' || *str == '\0')
			coeff[side][0] += tmp;
		else if ((*str == 'x' || *str == 'X') && *(str + 1) != '^')
		{
			coeff[side][1] += tmp;
			str++;
		}
		else
		{
			coeff[side][ft_atoi(str + 2)] += tmp;
			str += 3;
		}
	}
	return (coeff);
}

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

/*
** Finds the reduced form of the polynomial and prints it.
*/

double		**print_reduced(double **ptr, int *power)
{
	int		i;
	double	neg;

	i = 0;
	neg = 1.0;
	if (check_coeff(ptr, *power) == 0)
	{
		ft_printf("0 = 0\n");
		return (ptr);
	}
	while (i <= *power)
	{
		ptr[0][i] = ptr[0][i] - ptr[1][i];
		i++;
	}
	i = *power;
	while (ptr[0][i] == 0 && i >= 0)
		i--;
	*power = i;
	i = 0;
	while (i <= *power)
	{
		if (ptr[0][i] != 0)
		{
			if (i == 0)
				ft_printf("%g", ptr[0][i] * neg);
			else if (i == 1)
				ft_printf("%g * X", ptr[0][i] * neg);
			else
				ft_printf("%g * X^%d", ptr[0][i] * neg, i);
			i++;
			if (i <= *power && ptr[0][i] < 0)
			{
				ft_putstr(" - ");
				neg = -1.0;
			}
			else if (i <= *power && ptr[0][i] > 0)
			{
				ft_putstr(" + ");
				neg = 1.0;
			}
		}
		else if (++i <= *power && ptr[0][i] < 0)
		{
			ft_putstr(" - ");
			neg = -1.0;
		}
	}
	ft_putstr(" = 0\n");
	return (ptr);
}
