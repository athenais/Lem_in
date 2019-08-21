/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:10:54 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/23 16:12:16 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char						*ft_strchr(char const *s, int ch)
{
	register uint32_t		index;

	index = 0;
	if (s != NULL)
		while (s[index])
			if (s[index++] == (unsigned char)ch)
				return ((char *)s);
	return (ch ? NULL : (char *)s);
}
