/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:09:29 by aminadzh          #+#    #+#             */
/*   Updated: 2019/08/17 16:09:31 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "libft.h"

t_string	ft_string(const char *str)
{
	t_string	result;

	if (str != NULL)
		result.len = ft_strlen(str);
	else
		result.len = 0;
	result.capacity = result.len * 2;
	result.data = (char*)ft_memalloc(sizeof(char) * result.capacity);
	if (result.len != 0)
		ft_memcpy(result.data, str, result.len);
	return (result);
}

void		ft_append_str(t_string *s1, const t_string *s2)
{
	char	*buf;

	if (s1->capacity > s1->len + s2->len)
		ft_memcpy(&s1->data[s1->len], s2->data, s2->len);
	else
	{
		buf = (char*)ft_memalloc((s1->len + s2->len) * 2 * sizeof(char));
		ft_memmove(buf, s1->data, s1->len);
		ft_memmove(&buf[s1->len], s2->data, s2->len);
		free(s1->data);
		s1->data = buf;
		s1->len += s2->len;
		s1->capacity = s1->len * 2;
	}
}
