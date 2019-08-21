/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:50:32 by thflahau          #+#    #+#             */
/*   Updated: 2019/05/26 13:07:06 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in_compiler.h>
#include <lem_in_queue.h>
#include <stdlib.h>

/*
**	Cast the t_listhead pointer of the t_queue structure out to the
**	containing structure. Works just like the `container_of` macro from
**	the Linux kernel, file `include/linux/kernel.h` L.968
*/

inline t_queue			*ft_queue_entry(t_listhead *ptr)
{
	return ((t_queue *)((char *)ptr - __builtin_offsetof(t_queue, list)));
}

inline t_queue			*ft_queue_node(uint32_t key)
{
	t_queue				*node;

	if (UNLIKELY((node = (t_queue *)malloc(sizeof(t_queue))) == NULL))
		return (NULL);
	node->key = key;
	node->ant = 0;
	return (node);
}
