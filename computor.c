/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:50:02 by esterna           #+#    #+#             */
/*   Updated: 2017/08/29 18:00:14 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

/*
** Finds the value of the discriminant
*/

double		find_discrim(double *coeff)
{
	double discrim;
	double a;
	double b;
	double c;

	a = coeff[2];
	b = coeff[1];
	c = coeff[0];
	discrim = (b * b) - (4 * a * c);
	if (discrim > 0)
	{
		ft_putstr("Discriminant is strictly positive,");
		ft_putstr(" the two solutions are:\n");
	}
	else if (discrim == 0)
		ft_putstr("Discriminant is zero, the solution is:\n");
	else
	{
		ft_putstr("Discriminant is negative, ");
		ft_putstr("the two imaginary solutions are:\n");
	}
	return (discrim);
}

/*
** Solves for complex solutions when discriminant is negative.
*/

void		solve_complex(double *coeff, double discrim)
{
	double x;
	double i1;
	double i2;

	x = (-coeff[1]) / (2 * coeff[2]);
	i1 = (ft_sqrt(-discrim)) / (2 * coeff[2]);
	i2 = -i1;
	ft_printf("%g", x);
	if (i1 >= 0)
		ft_putstr(" + ");
	else
	{
		ft_putstr(" - ");
		i1 = -i1;
	}
	ft_printf("%gi\n", i1);
	ft_printf("%g", x);
	if (i2 >= 0)
		ft_putstr(" + ");
	else
	{
		ft_putstr(" - ");
		i2 = -i2;
	}
	ft_printf("%gi\n", i2);
}

/*
** Takes the coefficients and the discriminant,
** finds the solutions and prints them.
*/

void		solve_quadequ(double *coeff, double discrim)
{
	double x1;
	double x2;
	double a;
	double b;
	double c;

	a = coeff[2];
	b = coeff[1];
	c = coeff[0];
	if (discrim > 0)
	{
		x1 = (-b + ft_sqrt(discrim)) / (2 * a);
		x2 = (-b - ft_sqrt(discrim)) / (2 * a);
		ft_printf("%g\n%g\n", x1, x2);
	}
	else if (discrim == 0)
		ft_printf("%g\n", (-b) / (2 * a));
	else
		solve_complex(coeff, discrim);
}

/*
** Prints out the solution(s) based on the polynomial's power.
*/

void		print_power(int power, double **coeff)
{
	double tmp;

	if (power > 2)
	{
		ft_putstr("The polynomial degree is ");
		ft_putstr("strictly greater than 2, I can't solve.\n");
	}
	else if (power == 0 || check_coeff(coeff, power) == 0)
		ft_putstr("The solution is:\nAll Real numbers.\n");
	else if (power == 1)
	{
		ft_putstr("The solution is:\n");
		tmp = -coeff[0][0] / coeff[0][1];
		ft_printf("%g\n", tmp);
	}
	else
		solve_quadequ(coeff[0], find_discrim(coeff[0]));
}

/*
** The powerhouse function that receives and
** calls on all other functions, also has the function
** of sorting whether to solve the equation
** based on the polynomical's power.
*/

int			main(int argc, char **argv)
{
	int		power;
	double	**coeff;

	if (argc != 2)
		return (0);
	argv++;
	if (check_form(*argv) != 0)
	{
		coeff = find_coeff(*argv);
		power = (check_coeff(coeff, find_power(*argv)) == 0)
					? 0 : find_power(*argv);
		coeff = print_reduced(coeff, &power);
		ft_printf("Polynomial degree: %d\n", power);
		print_power(power, coeff);
	}
	else
		ft_printf("Error: Incorrect Formatting on Equation\n");
	return (0);
}
