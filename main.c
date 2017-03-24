/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 09:32:06 by esterna           #+#    #+#             */
/*   Updated: 2017/03/24 14:41:53 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Used to find the polynomial equation's power.*/
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

/*Checks to make sure that the polynomial equation is in a solvable/normal form.*/
int			check_form(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen((const char *)str);
	while (i < len)
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		while (ft_isdigit(str[i]) || str[i] == '.')
			i++;
		if (str[i] != ' ' && str[i] != '*')
			return (0);
		while (str[i] == ' ' || str[i] == '*')
			i++;
		if (str[i] != 'X' && str[i] != 'x' || str[++i] != '^' || ft_isdigit(str[++i]) == 0)
			return (0);
		i++;
		while (str[i] == ' ' || str[i] == '+' || str[i] == '-' || str[i] == '=')
			i++;
	}
	return (1);
}

/*Finds the coeffiecients of all the powers and sorts them, for both the left and right of the equation.*/
float		**find_coeff(char *str)
{
	int		side;
	int		neg;
	float	tmp;
	float 	**coeff;

	side = 0;
	coeff = (float **)malloc(sizeof(float *) * 2);
	coeff[0] = (float *)malloc(sizeof(float) * (tmp = (float)find_power(str)));
	coeff[1] = (float *)malloc(sizeof(float) * tmp);
	ft_bzero(coeff[0], sizeof(float)*(size_t)tmp);
	ft_bzero(coeff[1], sizeof(float)*(size_t)tmp);
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str == '=')
		{
			side++;
			str++;
		}
		neg = (*str == '-') ? -1 : 1;
		while (!(ft_isdigit(*str)))
			str++;
		tmp = neg * ft_atof(str);
		while (ft_isdigit(*str) || *str == '.')
			str++;
		while (!(ft_isdigit(*str)))
			str++;
		coeff[side][ft_itoa(str)] = tmp;
		str++;
	}
	return (coeff);
}

/*Finds the reduced form of the polynomial and prints it.*/
float		**print_reduced(float **ptr, int power)
{
	int i;
	float tmp;

	i = 0;
	while (i <= power)
		ptr[0][i] = ptr[0][i] + ptr[1][i];
	i = 0;
	while (i <= power)
	{
		ft_putnbr((int)ptr[0][i]);
		ft_putchar('.');
		tmp = ptr[0][i];
		while (tmp % 1)
		{
			tmp *= 10;
			ft_putnbr(tmp);
		}
		ft_putstr(" * X^");
	   	ft_putnbr(i);
		i++;
		if (i <= power && ptr[0][i] < 0)
			ft_putstr(" - ");
		else if (i <= power && ptr[0][i] > 0)
			ft_putstr(" + ");
	}
	ft_putstr(" = 0\n");
	return(ptr);
}

/*Finds the value of the discriminant*/
float		find_discrim(float *coeff)
{
	float discrim;
	float a;
	float b;
	float c;

	a = coeff[2];
	b = coeff[1];
	c = coeff[0];
	discrim = (b * b) - (4 * a * c);
	if (discrim > 0)
		ft_putstr("Discriminant is strictly positive, the two solutions are:\n");
	else if (discrim == 0)
		ft_putstr("Discriminant is zero, the solution is:\n");
	else
		ft_putstr("Discriminant is negative, the two imaginary solutions are:\n");
	return (discrim);
}

/*Takes the coefficients and the discriminant, finds the solutions and prints them.*/
void		solvequadequ(float *coeff, float discrim)
{
	float x1;
	float x2;
	float a;
	float b;
	float c;
	char **solutions;

	a = coeff[2];
	b = coeff[1];
	c = coeff[0];
	if (discrim > 0)
	{
		x1 = (-b + ft_sqrt(discrim))/(2 * a);
		x2 = (-b - ft_sqrt(discrim))/(2 * a);
		ft_putfloat(x1);
		ft_putchar('\n');
		ft_putfloat(x2);
		ft_putchar('\n');
	}
	else if (discrim == 0)
	{
		x1 = (-b)/(2 * a);
		ft_putfloat(x1);
		ft_putchar('\n');
	}
	else
		solve_complex(coeff, discrim);
}

/*Solves for complex solutions when discriminant is negative.*/
void		solve_complex(float *coeff, float disrcim)
{
	char **solutions;
	float x;
	float i1;
	float i2;

	solutions = (char **)malloc(sizeof(char *) * 2);
	solutions[0] = (char *)malloc(sizeof(char) * 20);
	solutions[1] = (char *)malloc(sizeof(char) * 20);

	x = (-b)/(2 * a);
	i1 = ft_sqrt(-discrim)/(2 * a);
	i2 = -(ft_sqrt(-discrim)/(2 * a);
	ft_putstr(ft_ftoa(x));
	if (i1 > 0)
		ft_putstr(" + ");
	else
	{
		ft_putstr(" - ");
		i1 = -i1;
	}
	ft_putstr(ft_ftoa(i1));
	ft_putstr("i\n");

	ft_putstr(ft_ftoa(x));
	if (i2 > 0)
		ft_putstr(" + ");
	else
	{
		ft_putstr(" - ");
		i2 = -i2;
	}
	ft_putstr(ft_ftoa(i2));
	ft_putstr("i\n");	
}

/*The powerhouse function that receives and calls on all other functions, also has the function of sorting whether to solve the equation based on the polynomical's power.*/
int			main(int argc, char **argv)
{
	int		power;
	float	**coeff;
	float	tmp;

	if (argc != 2)
		return (0);
	argv++;
	if (check_form(*argv))
	{
		power = find_power(*argv);
		coeff = find_coeff(*argv);
		coeff = print_reduced(coeff, power);
		ft_putstr("Polynomial degree: ");
		ft_putnbr(power);
		ft_putchar('\n');
		if (power > 2)
			ft_putstr("The polynomial degree is strictly greater than 2, I can't solve.\n");
		else if (power == 0)
			ft_putstr("The solution is:\nAll Real numbers.\n");
		else if (power == 1)
		{
			ft_putstr("The solution is:\n");
			tmp = -coeff[0][0]/coeff[0][1];
			ft_putnbr((int)tmp);
			ft_putchar('.');
			while (tmp % 1)
			{
				tmp *= 10;
				ft_putnbr(tmp);
			}
		}
		else
			solve_quadequ(coeff[0], find_dicrim(coeff[0]);
	}
	return (0);
}
