/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:43:04 by esterna           #+#    #+#             */
/*   Updated: 2017/08/29 21:12:15 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

/*
** Checks to make sure that the polynomial
** equation is in a solvable/normal form.
*/

int			check_form(char *str)
{
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
		{
			str = fast_forward(str, '1');
			if (*str == '\0')
				return (1);
			if (*str != '+' && *str != '-' && *str != '=' && *str != '*')
				return (0);
			str++;
			if (*str == '+' || *str == '-' || *str == '=' || *str == '*')
				return (0);
			str = fast_forward(str, '2');
		}
		if (*str == 'X' || *str == 'x')
		{
			if (*(str + 1) == '^' && ft_isdigit(*(str + 2)) == 0)
				return (0);
			str = str + (*(str + 1) == '^' ? 3 : 1);
		}
		str = fast_forward(str, '3');
	}
	return (1);
}
