/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:05:33 by esterna           #+#    #+#             */
/*   Updated: 2017/03/23 16:33:11 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (ft_isspace(*nbr))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
	{
		neg = (*nbr == '-') ? -1 : 1;
		nbr++;
	}
	while (ft_isdigit(*nbr))
	{
		result = result * 10 + (*nbr - '0');
		nbr++;
	}
	if (*nbr == '.')
		nbr++;
	while (ft_isdigit(*nbr))
	{
		result = result * 10 + (*nbr - '0');
		nbr++;
		power *= 10.0;
	}
	result = neg * result / power;
	return (result);
}
