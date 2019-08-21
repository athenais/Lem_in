/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:41:57 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/08 13:07:06 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_bug.h>
#include <lem_in_queue.h>
#include <lem_in_compiler.h>

static inline uint8_t	ft_hardware_memalloc_failure(t_map *map, uint16_t size)
{
	register uint16_t	index;

	index = 0;
	ft_printf("lem-in: %s (hint: %s)\n", MEMERR, MEMFULL);
	while (index <= size)
		if (LIKELY(map->hashtab[index++] != NULL))
			free((void *)map->hashtab[index - 1]);
	return (EXIT_FAILURE);
}

uint8_t					ft_initialize_hashtable(t_map *map)
{
	register uint16_t	idx;

	idx = 0;
	if (UNLIKELY(MAX_VERTICES > UINT16_MAX))
		return (ft_puterror(EMAXVERT));
	while (idx < MAX_VERTICES)
	{
		if (!(map->hashtab[idx] = (t_vertices *)malloc(sizeof(t_vertices))))
			return (ft_hardware_memalloc_failure(map, --idx));
		ft_memset(map->hashtab[idx], 0, sizeof(t_vertices));
		idx++;
	}
	return (EXIT_SUCCESS);
}

static void				ft_free_adjacency_list(t_edges **head)
{
	t_edges				*ptr;
	t_edges				*node;

	if (LIKELY(head != NULL && *head != NULL))
	{
		node = *head;
		while (node != NULL)
		{
			ptr = node->next;
			free((void *)node);
			node = ptr;
		}
	}
}

int						ft_free_hashtable(t_vertices *hashtab[MAX_VERTICES])
{
	register uint16_t	index;

	index = 0;
	while (index < MAX_VERTICES)
	{
		ft_free_adjacency_list(&hashtab[index]->adjc);
		if (LIKELY(hashtab[index]->name != NULL))
			free((void *)hashtab[index]->name);
		free((void *)hashtab[index++]);
	}
	return (EXIT_SUCCESS);
}

inline uint8_t			ft_list_del(t_listhead *head)
{
	t_listhead			*node;
	t_listhead			*next;

	node = head->next;
	next = node->next;
	while (node != head)
	{
		free((void *)ft_queue_entry(node));
		node = next;
		next = node->next;
	}
	return (EXIT_SUCCESS);
}
