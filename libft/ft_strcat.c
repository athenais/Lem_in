/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:34:24 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/08 11:19:54 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

inline char				*ft_strcat(char *s1, char const *s2)
{
	char				*ptr;

	ptr = s1;
	s1 += ft_strlen(s1);
	while (*s2)
		*s1++ = *s2++;
	*s1 = 0;
	return (ptr);
}
