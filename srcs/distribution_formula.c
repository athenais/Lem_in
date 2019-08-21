/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribution_formula.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:07:04 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/11 12:21:10 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

double					func2(int32_t pop, int32_t diff, int32_t paths)
{
	return (((double)(pop + diff) / (double)paths) + 1);
}
