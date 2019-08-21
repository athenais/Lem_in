/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:34:22 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/16 17:05:06 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <lem_in_bug.h>
#include "../libft/libft.h"

uint8_t				ft_puterror(char const *error)
{
	ft_printf(C_RED"%s"C_NONE, error);
	return (EXIT_FAILURE);
}

void				ft_print_usage(char const *name)
{
	ft_printf("usage:\t%s [-v]\n\t%s [-v] < file\n\tfile | %s [-v]\n", \
		name, name, name);
}
