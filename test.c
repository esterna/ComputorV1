/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:30:50 by esterna           #+#    #+#             */
/*   Updated: 2017/03/23 19:39:13 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

double		ft_atof(char *nbr)
{
	int		neg;
	int		power;
	double	result;

	neg = 1;
	power = 1;
	result = 0;
	if (!nbr)
		return (0);
	while (isspace(*nbr))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
	{
		neg = (*nbr == '-') ? -1 : 1;
		nbr++;
	}
	while (isdigit(*nbr))
	{
		result = result * 10 + (*nbr - '0');
		nbr++;
	}
	if (*nbr == '.')
		nbr++;
	while (isdigit(*nbr))
	{
		result = result * 10 + (*nbr - '0');
		nbr++;
		power *= 10.0;
	}
	result = neg * result / power;
	return (result);
}

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

float		**find_coeff(char *str)
{
	int		side;
	int		neg;
	float	tmp;
	float 	**coeff;

	side = 0;
	;
	coeff = (float **)malloc(sizeof(float *) * 2);
	coeff[0] = (float *)malloc(sizeof(float) *
			(tmp = (float)find_power(str) + 1));
	coeff[1] = (float *)malloc(sizeof(float) * tmp);
	bzero(coeff[0], sizeof(float) * (size_t)tmp);
	bzero(coeff[1], sizeof(float) * (size_t)tmp);
	while (*str)
	{
		while (isspace(*str))
			str++;
		if (*str == '=')
		{
			side++;
			str++;
		}
		neg = (*str == '-') ? -1 : 1;
		while (!(isdigit(*str)))
			str++;
		tmp = neg * ft_atof(str);
		while (isdigit(*str) || *str == '.')
			str++;
		while (!(isdigit(*str)))
			str++;
		coeff[side][atoi(str)] = tmp;
		str++;
	}
	return (coeff);
}

int main()
{
	int i = 0;
	int n = 0;

	char *test = "30000000 * X^0      =     0.000009 * X^0";
	float **ptr = find_coeff(test);
	printf("Original: %s\n\n", test);
	int power = find_power(test);
	while (i <= 1)
	{
		n = 0;
		printf("%d of Equation: \n", i + 1);
		while (n <= power)
		{
			printf("Power %d's coefficient : %f\n", n, ptr[i][n]);
			n++;
		}
		printf("\n");
		i++;
	}

	return 0;
}
