/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:35:11 by esterna           #+#    #+#             */
/*   Updated: 2017/08/29 15:28:18 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atod(char *nbr)
{
	int		neg;
	int		power;
	double	result;

	neg = 1;
	power = 1;
	result = 0;
	if (!nbr)
		return (0);
	while (ft_isspace(*nbr) != 0 && *nbr != '\0')
		nbr++;
	if ((*nbr == '-' || *nbr == '+') && nbr++)
		neg = (*(nbr - 1) == '-') ? -1 : 1;
	while (ft_isdigit(*nbr) != 0)
		result = result * 10 + (*(nbr++) - '0');
	nbr += (*nbr == '.') ? 1 : 0;
	while (ft_isdigit(*nbr) != 0)
	{
		result = result * 10 + (*(nbr++) - '0');
		power *= 10.0;
	}
	return (result = neg * result / power);
}
