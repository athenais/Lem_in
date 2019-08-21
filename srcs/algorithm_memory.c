/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:06:21 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/16 18:53:54 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_list.h>
#include <lem_in_stacks.h>
#include <lem_in_compiler.h>

uint32_t					**ft_initialize_tab(void)
{
	uint32_t				**tab;

	tab = NULL;
	if (LIKELY((tab = (uint32_t **)malloc(sizeof(uint32_t *) << 5)) != NULL))
		ft_memset(tab, 0, (sizeof(uint32_t *) << 5));
	return (tab);
}

void						ft_join_paths(t_map *map, t_listhead *head)
{
	t_queue					*list;
	t_stack					*node;
	t_vertices				*vertex;

	if (LIKELY((node = ft_stack_node()) != NULL))
	{
		if (LIKELY((node->path = (t_queue *)malloc(sizeof(t_queue))) != NULL))
			ft_list_init_head(&(node->path->list));
		vertex = map->hashtab[map->end_index];
		while (vertex != NULL)
		{
			if (LIKELY((list = ft_queue_node((uint32_t)vertex->key)) != NULL))
			{
				ft_list_push(&(list->list), &(node->path->list));
				++node->size;
			}
			vertex = vertex->prev;
		}
		ft_list_add_tail(&(node->list), head);
	}
}

void						ft_free_tab(uint32_t **tab)
{
	register uint16_t		index;

	index = 0;
	if (LIKELY(tab != NULL))
	{
		while (index < 32U)
		{
			if (tab[index])
				free((void *)tab[index]);
			else
				break ;
			++index;
		}
		free((void *)tab);
	}
}
