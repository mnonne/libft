/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:18:38 by aminadzh          #+#    #+#             */
/*   Updated: 2019/08/24 13:18:40 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "test.h"
#include "libft.h"

static int		test_string_replace2(t_string str)
{
	ft_string_replace(&str, 15, 10, "sssssss");
	if (ft_strcmp(str.data, "ThiThat stringsssssss") != 0 || str.len != 21)
	{
		ft_putendl("String replace failed");
		return (-1);
	}
	ft_string_replace(&str, 22, 15, "qwertyuiopasdfg");
	if (ft_strcmp(str.data, "ThiThat stringsssssssqwertyuiopasdfg") != 0 ||
		str.len != 36 || str.capacity != 72)
	{
		ft_putendl("String replace failed");
		return (-1);
	}
	return (0);
}

int				test_string_replace(void)
{
	t_string	str;

	str = ft_string("This is string");
	ft_string_replace(&str, 16, 4, "That");
	if (ft_strcmp(str.data, "This is string") != 0 || str.len != 14)
	{
		ft_putendl("String replace failed");
		return (-1);
	}
	ft_string_replace(&str, 4, 4, "That");
	if (ft_strcmp(str.data, "ThiThat string") != 0 || str.len != 14)
	{
		ft_putendl("String replace failed");
		return (-1);
	}
	test_string_replace2(str);
	return (0);
}
