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

typedef struct	s_string
{
	char		*data;
	size_t		len;
	size_t		capacity;
}				t_string;

t_string		ft_string(const char *str);
void			ft_append_str(t_string *s1, const t_string *s2);

#endif
