/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:19:40 by thflahau          #+#    #+#             */
/*   Updated: 2019/05/17 21:04:05 by abrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_hash.h>

uint32_t				hash(const char *s)
{
	uint32_t			h;

	h = 0;
	while (*s)
	{
		h = h * MULTIPLIER + *s;
		s++;
	}
	return (h % MAX_VERTICES);
}

uint32_t				hashn(const char *s, size_t size)
{
	uint32_t			h;
	size_t				ind;

	h = 0;
	ind = 0;
	while (*s && ind++ < size)
	{
		h = h * MULTIPLIER + *s;
		s++;
	}
	return (h % MAX_VERTICES);
}
