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

void		ft_string_append(t_string *s1, const char *s2)
{
	char	*buf;
	size_t	s_len;

	s_len = 0;
	if (s2 != NULL)
		s_len = ft_strlen(s2);
	if (s1->capacity > s1->len + s_len)
	{
		ft_memcpy(&s1->data[s1->len], s2, s_len);
		s1->len += s_len;
	}
	else
	{
		buf = (char*)ft_memalloc((s1->len + s_len) * 2 * sizeof(char));
		ft_memmove(buf, s1->data, s1->len);
		ft_memmove(&buf[s1->len], s2, s_len);
		free(s1->data);
		s1->data = buf;
		s1->len += s_len;
		s1->capacity = s1->len * 2;
	}
}

void		ft_string_destroy(t_string *str)
{
	if (str->capacity > 0)
		free(str->data);
	str->capacity = 0;
	str->len = 0;
}

size_t		ft_string_find(t_string *str, const char *find, size_t pos)
{
	char	*found;

	if (pos >= str->len)
		return (STR_NPOS);
	found = ft_strstr(str->data + pos, find);
	if (!found)
		return (STR_NPOS);
	return (found - str->data);
}

void		ft_string_replace(t_string *str, size_t pos, size_t len,
		const char *src)
{
	char	*buffer;
	size_t	src_len;

	if (pos > str->len + 1)
		return ;
	src_len = ft_strlen(src);
	len = (len <= src_len) ? len : src_len;
	if (pos - 1 + len > str->capacity)
	{
		buffer = (char*)ft_memalloc(((pos - 1 + len > str->len + len) ?
				pos - 1 + len : str->len + len) * 2 * sizeof(char));
		ft_memcpy(buffer, str->data, pos - 1);
	}
	else
		buffer = str->data;
	ft_memmove(buffer + pos - 1, src, len);
	if (pos - 1 + len > str->capacity)
	{
		free(str->data);
		str->data = buffer;
		str->capacity = ((pos - 1 + len > str->len + len) ?
				pos - 1 + len : str->len + len) * 2;
	}
	if (str->len < pos - 1 + len)
		str->len = pos - 1 + len;
}
