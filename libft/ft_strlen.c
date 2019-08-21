/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:54:51 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/08 11:23:31 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

inline size_t			ft_strlen(char const *str)
{
	char				*ptr;

	ptr = (char *)str;
	while (__builtin_expect(!!(*ptr), 1))
		ptr++;
	return (ptr - str);
}
