/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 09:59:25 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/15 18:25:44 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in_bug.h>
#include <lem_in_stacks.h>
#include <lem_in_compiler.h>
#include <lem_in_algorithm.h>

inline void				ft_update_visited_array(int8_t *array, t_listhead *head)
{
	t_listhead			*ref;
	t_listhead			*node;
	t_listhead			*position;

	position = head->next;
	ft_fast_bzero(array, MAX_VERTICES);
	while ((position = position->next) != head)
	{
		ref = &(ft_stack_entry(position)->path->list);
		node = ref->next;
		while ((node = node->next) != ref->prev)
			array[ft_queue_entry(node)->key] = visited_node;
	}
}

uint8_t					ft_algorithm(t_map *map)
{
	uint32_t			**tab;
	void				(*funptr[2])(t_map *, uint32_t **, int32_t);

	funptr[0] = &ft_simple_pathfinding;
	funptr[1] = &ft_advanced_pathfinding;
	tab = ft_search_for_overlaps(map);
	ft_reinitialize_graph(map);
	funptr[!!(tab)](map, tab, 1);
	ft_free_tab(tab);
	return (EXIT_SUCCESS);
}
