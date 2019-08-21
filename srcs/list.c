/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:36:02 by thflahau          #+#    #+#             */
/*   Updated: 2019/05/24 13:03:08 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in_list.h>
#include <lem_in_queue.h>
#include <lem_in_compiler.h>
#include <stdlib.h>

/*
**	These are easy-to-use, highly portable functions for manipulating
**	circular linked lists. This implementation comes from the Linux
**	kernel source tree, file `include/linux/list.h`
*/

inline void				ft_list_init_head(t_listhead *head)
{
	head->next = head;
	head->prev = head;
}

/*
**	Insert a new entry between two known consecutive entries (prev & next).
**	This is only for internal list manipulation where we know the `prev`
**	and `next` pointers.
*/

inline void				ft_list_add(t_listhead *node,
									t_listhead *prev,
									t_listhead *next)
{
	next->prev = node;
	node->next = next;
	node->prev = prev;
	prev->next = node;
}

/*
**	Insert a new entry AFTER the specified head. This is good for
**	implementing stacks.
*/

inline void				ft_list_push(t_listhead *node, t_listhead *head)
{
	ft_list_add(node, head, head->next);
}

inline void				ft_list_pop(t_listhead *node)
{
	node->next->prev = node->prev;
	node->prev->next = node->next;
	free((void *)ft_queue_entry(node));
}

/*
**	Insert a new entry BEFORE the specified head. This is good for
**	implementing queues.
*/

inline void				ft_list_add_tail(t_listhead *node, t_listhead *head)
{
	ft_list_add(node, head->prev, head);
}
