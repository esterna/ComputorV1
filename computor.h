/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:44:07 by esterna           #+#    #+#             */
/*   Updated: 2017/08/29 21:04:22 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include "libft.h"
# include "libftprintf.h"

int			check_form(char *str);

double		**find_coeff(char *str);

int			find_power(char *str);

int			check_coeff(double **coeff, int power);

double		**print_reduced(double **ptr, int *power);

char		*fast_forward(char *str, int x);

int			check_power(double **coeff, int power);

#endif
