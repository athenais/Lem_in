/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:20:22 by thflahau          #+#    #+#             */
/*   Updated: 2019/05/26 15:09:13 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in_list.h>
#include <lem_in_parsing.h>
#include <lem_in_compiler.h>
#include <stdlib.h>
#include "../libft/libft.h"

/*
**	Cast the t_listhead pointer of the t_input structure out to the
**	containing structure. Works just like the `container_of` macro from
**	the Linux kernel, file `include/linux/kernel.h` L.968
*/

inline t_input			*ft_input_entry(t_listhead *ptr)
{
	return ((t_input *)((char *)ptr - __builtin_offsetof(t_input, list)));
}

inline t_input			*ft_make_node(char *buffer)
{
	t_input				*node;

	if (UNLIKELY((node = (t_input *)malloc(sizeof(t_input))) == NULL))
		return (NULL);
	node->buffer = buffer;
	return (node);
}

inline uint8_t			ft_parsing_panic(t_listhead *head, char const *str)
{
	t_input				*ptr;
	t_listhead			*node;
	t_listhead			*next;

	if (LIKELY(str != NULL))
		free((void *)str);
	node = head->next;
	next = node->next;
	while (node != head)
	{
		if (LIKELY((ptr = ft_input_entry(node)) != NULL))
		{
			free((void *)ptr->buffer);
			free((void *)ptr);
		}
		node = next;
		next = node->next;
	}
	return (EXIT_FAILURE);
}

inline void				ft_safe_print_and_free(t_listhead *head)
{
	t_input				*ptr;
	t_listhead			*node;
	t_listhead			*next;

	node = head->next;
	next = node->next;
	while (node != head)
	{
		if (LIKELY((ptr = ft_input_entry(node)) != NULL))
		{
			ft_putstr_endl_free(ptr->buffer);
			free((void *)ptr);
		}
		node = next;
		next = node->next;
	}
}
