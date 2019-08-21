/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_overlaps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:09:58 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/17 16:13:50 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_stacks.h>
#include <lem_in_compiler.h>
#include <lem_in_algorithm.h>

inline void				ft_add_overlap(t_map *map, uint32_t pk, uint32_t hk)
{
	t_edges				*node;

	node = map->hashtab[pk]->adjc;
	while (node != NULL && node->key != hk)
		node = node->next;
	node->way = closed_way;
	node = map->hashtab[hk]->adjc;
	while (node != NULL && node->key != pk)
		node = node->next;
	node->way = closed_way;
}

static void				ft_actually_put_into_tab(t_map *map, t_listhead *head,
																uint32_t *tab)
{
	uint32_t			hashkey;
	uint32_t			prevkey;
	t_listhead			*position;

	position = head->next;
	prevkey = ft_queue_entry(head->next)->key;
	while ((position = position->next) != head)
	{
		hashkey = ft_queue_entry(position)->key;
		if (ft_overlaps(map, prevkey, hashkey) == EXIT_SUCCESS)
		{
			tab[0] = prevkey;
			tab[1] = hashkey;
		}
		prevkey = hashkey;
	}
}

static inline uint8_t	ft_put_into_tab(t_map *map, t_listhead *head,
										uint32_t **tab)
{
	register uint16_t	ix;

	ix = 0;
	while (tab[ix] != 0)
		++ix;
	if (UNLIKELY(ix >= 32))
		return (EXIT_FAILURE);
	if (UNLIKELY(!(tab[ix] = (uint32_t *)malloc(sizeof(uint32_t) << 1))))
		return (EXIT_FAILURE);
	ft_actually_put_into_tab(map, &(ft_stack_entry(head)->path->list), tab[ix]);
	return (EXIT_SUCCESS);
}

static uint8_t			ft_check_if_overlap(t_map *map, t_listhead *head)
{
	uint32_t			prevkey;
	uint32_t			hashkey;
	t_listhead			*position;
	t_listhead			*new;

	new = &(ft_stack_entry(head)->path->list);
	position = new;
	prevkey = ft_queue_entry(new->next)->key;
	while ((position = position->next) != new)
	{
		hashkey = ft_queue_entry(position)->key;
		if (ft_overlaps(map, prevkey, hashkey) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		prevkey = hashkey;
	}
	return (EXIT_FAILURE);
}

uint32_t				**ft_search_for_overlaps(t_map *map)
{
	t_stack				stacks;
	uint32_t			**overlaps;
	int8_t				visited[MAX_VERTICES];

	overlaps = NULL;
	ft_list_init_head(&(stacks.list));
	ft_fast_bzero(visited, MAX_VERTICES);
	while (ft_breadth_first_search(map, visited) == EXIT_SUCCESS)
	{
		ft_join_paths(map, &(stacks.list));
		ft_fast_bzero(visited, MAX_VERTICES);
		ft_make_directed(map, stacks.list.prev);
		if (ft_check_if_overlap(map, stacks.list.prev) == EXIT_SUCCESS)
		{
			if (overlaps == NULL)
				if (UNLIKELY((overlaps = ft_initialize_tab()) == NULL))
					return (NULL);
			ft_put_into_tab(map, stacks.list.prev, overlaps);
		}
	}
	ft_free_stacks(&(stacks.list));
	return (overlaps);
}
