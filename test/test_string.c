/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:49:03 by aminadzh          #+#    #+#             */
/*   Updated: 2019/08/17 16:49:04 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "test.h"
#include "libft.h"

int			test_string_append(t_string cont1, const char *s1)
{
	t_string	cont2;
	char		*compare;

	cont2 = ft_string(" other");
	compare = ft_strjoin(cont1.data, cont2.data);
	ft_append_str(&cont1, &cont2);
	if (ft_strcmp(cont1.data, compare) != 0)
	{
		ft_putendl(cont1.data);
		ft_putendl("Small string concat faield");
		free(compare);
		return (-1);
	}
	free(compare);
	return (0);
}

int			test_string_append2(void)
{
	t_string	s1;
	t_string	s2;
	char		*compare;

	s1 = ft_string("New");
	s2 = ft_string(" joined string");
	compare = ft_strjoin(s1.data, s2.data);
	ft_append_str(&s1, &s2);
	if (ft_strcmp(s1.data, compare) != 0)
	{
		ft_putendl(s1.data);
		ft_putendl("Large string concat faield");
		free(compare);
		return (-1);
	}
	free(compare);
	return (0);
}

int			test_empty1(void)
{
	t_string	s1;
	t_string	s2;
	t_string	s3;

	s1 = ft_string(NULL);
	s2 = ft_string("KEK");
	s3 = ft_string(NULL);
	ft_append_str(&s1, &s2);
	if (ft_strcmp(s1.data, s2.data) != 0)
	{
		ft_putendl(s1.data);
		ft_putendl("Empty string concat failed");
		return (-1);
	}
	ft_append_str(&s2, &s3);
	if (ft_strcmp(s1.data, s2.data) != 0)
	{
		ft_putendl(s2.data);
		ft_putendl("Empty string concat failed");
		return (-1);
	}
	return (0);
}

int			test_string(void)
{
	t_string	str1;

	str1 = ft_string("New string");
	if (ft_strcmp(str1.data, "New string") != 0)
	{
		ft_putendl("String construction failed");
		return (-1);
	}
	if (test_string_append(str1, str1.data) < 0)
		return (-1);
	if (test_string_append2() < 0)
		return (-1);
	if (test_empty1() < 0)
		return (-1);
	return (0);
}
