/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:43:22 by aminadzh          #+#    #+#             */
/*   Updated: 2019/08/29 16:43:23 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	get_exponenta(const char *str)
{
	double		result;
	int			i;
	int 		pow;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (ft_minpow(result, -i));
}

static float	get_mantissa(const char *str, int *i)
{
	double		result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

float 	ft_atof(const char *str)
{
	float	mantissa;
	float	exponenta;
	int 	i;
	int 	flag;

	flag = 0;
	i = 0;
	exponenta = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i += 1;
	if (str[i] == '-')
	{
		flag = 1;
		i++;
	}
	mantissa = get_mantissa(str, &i);
	if (str[i] == '.')
	{
		i++;
		exponenta = get_exponenta(str + i);
	}
	return (flag == 1) ? (-mantissa - exponenta) : (mantissa + exponenta);
}
