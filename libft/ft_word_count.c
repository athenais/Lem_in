/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:56:53 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/08 11:24:18 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

uint32_t				ft_word_count(char const *str)
{
	uint32_t			words;

	words = 0;
	while (*str)
	{
		if (ft_isblank(*str) == 0)
		{
			++words;
			while (ft_isblank(*str) == 0 && *str)
				if (__builtin_expect(!ft_isprintable(*str++), 0))
					return (0);
		}
		else
			str++;
	}
	return (words);
}
