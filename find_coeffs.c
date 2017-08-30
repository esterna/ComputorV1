/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coeffs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:47:00 by esterna           #+#    #+#             */
/*   Updated: 2017/08/29 18:05:23 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

/*
** Used to find the polynomial equation's power.
*/

int			find_power(char *str)
{
	int		p;

	p = 0;
	while (*str)
	{
		if ((*str == 'x' || *str == 'X') && *(str + 1) != '^' && p <= 1)
			p = 1;
		if (*str == '^' && str++)
			p = (*str - '0' > p) ? *str - '0' : p;
		str++;
	}
	return (p);
}

double		**init_2d_dbl(char *str)
{
	int		side;
	double	**coeff;

	side = find_power(str) + 1;
	coeff = (double **)malloc(sizeof(double *) * 2);
	coeff[0] = (double *)malloc(sizeof(double) * side);
	coeff[1] = (double *)malloc(sizeof(double) * side);
	ft_bzero(coeff[0], sizeof(double) * side);
	ft_bzero(coeff[1], sizeof(double) * side);
	return (coeff);
}

char		*fast_forward(char *str, int x)
{
	if (x == ' ')
		while (ft_isspace(*str) != 0)
			str++;
	else if (x == 'x')
		while (ft_isdigit(*str) == 0 && *str != 'x' &&
				*str != 'X' && *str != '\0')
			str++;
	else if (x == '.')
		while ((ft_isdigit(*str) == 1 || *str == '.' ||
					ft_isspace(*str) == 1 || *str == '*') && *str != '\0')
			str++;
	else if (x == '1')
		while (ft_isdigit(*str) || *str == '.' || ft_isspace(*str))
			str++;
	else if (x == '2')
		while (ft_isspace(*str) || *str == '+' ||
				*str == '-' || *str == '=' || *str == '*')
			str++;
	else if (x == '3')
		while (ft_isspace(*str) || *str == '+' || *str == '-' || *str == '=')
			str++;
	return (str);
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

	side = 0;
	coeff = init_2d_dbl(str);
	while (*(str = fast_forward(str, ' ')) != '\0')
	{
		side += (*str == '=' && str++) ? 1 : 0;
		neg = (*str == '-') ? -1 : 1;
		str = fast_forward(str, 'x');
		tmp = neg * ((*str == 'x' || *str == 'X') ? 1 : ft_atod(str));
		str = fast_forward(str, '.');
		if (*str == '+' || *str == '-' || *str == '=' || *str == '\0')
			coeff[side][0] += tmp;
		else if ((*str == 'x' || *str == 'X') && *(str + 1) != '^' && str++)
			coeff[side][1] += tmp;
		else
		{
			coeff[side][ft_atoi(str + 2)] += tmp;
			str += 3;
		}
	}
	return (coeff);
}
