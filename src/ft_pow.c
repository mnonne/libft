/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:46:14 by aminadzh          #+#    #+#             */
/*   Updated: 2019/08/29 17:46:15 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_minpow(int nb, int pow)
{
	double	res;

	res = nb;
	if (pow == 0)
		return (1);
	if (pow < 0)
	{
		while (pow++ < 0)
			res /= 10;
	}
	return (res);
}

long int	ft_pow(int nb, int pow)
{
	long int	res;

	res = nb;
	if (pow == 0)
		return (1);
	if (pow > 0)
	{
		while (pow-- > 0)
			res *= nb;
	}
	return (res);
}
