/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:04:21 by aminadzh          #+#    #+#             */
/*   Updated: 2019/08/17 16:04:23 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
# include <stdint.h>

# define STR_NPOS SIZE_MAX

typedef struct	s_string
{
	char		*data;
	size_t		len;
	size_t		capacity;
}				t_string;

t_string		ft_string(const char *str);
void			ft_string_append(t_string *s1, const char *s2);
void			ft_string_destroy(t_string *str);
size_t			ft_string_find(t_string *str, const char *find, size_t pos);

#endif
