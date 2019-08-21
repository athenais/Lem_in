/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:05:49 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/03 14:38:17 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in_stacks.h>
#include <lem_in_compiler.h>
#include "../libft/libft.h"

/*
**	Cast the t_listhead pointer of the t_stack structure out to the
**	containing structure. Works just like the `container_of` macro from
**	the Linux kernel, file `include/linux/kernel.h` L.968
*/

inline t_stack				*ft_stack_entry(t_listhead *ptr)
{
	return ((t_stack *)((char *)ptr - __builtin_offsetof(t_stack, list)));
}

inline t_stack				*ft_stack_node(void)
{
	t_stack					*head;

	if (UNLIKELY((head = (t_stack *)malloc(sizeof(t_stack))) == NULL))
		return (NULL);
	ft_memset(head, 0, sizeof(t_stack));
	return (head);
}

void						ft_free_stacks(t_listhead *head)
{
	t_listhead				*node;
	t_listhead				*next;

	node = head->next;
	while (node != head)
	{
		next = node->next;
		ft_list_del(&(ft_stack_entry(node)->path->list));
		free((void *)ft_stack_entry(node)->path);
		free((void *)ft_stack_entry(node));
		node = next;
	}
	ft_list_init_head(head);
}
