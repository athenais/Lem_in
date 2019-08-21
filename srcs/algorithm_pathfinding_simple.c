/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_pathfinding_simple.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:03:22 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/16 19:24:12 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_bug.h>
#include <lem_in_stacks.h>
#include <lem_in_compiler.h>
#include <lem_in_algorithm.h>

void					ft_simple_pathfinding(t_map *map, uint32_t **tab,
												int32_t s)
{
	t_stack				stacks;
	int8_t				visited[MAX_VERTICES];

	(void)tab;
	ft_list_init_head(&(stacks.list));
	ft_fast_bzero(visited, MAX_VERTICES);
	while (ft_breadth_first_search(map, visited) == EXIT_SUCCESS)
	{
		ft_join_paths(map, &(stacks.list));
		ft_update_visited_array(visited, &(stacks.list));
		if (ft_stack_entry(stacks.list.prev)->size == 2)
			break ;
	}
	if (UNLIKELY(stacks.list.prev == &(stacks.list)))
	{
		ft_free_stacks(&(stacks.list));
		ft_puterror(DEADEND);
	}
	else
	{
		ft_delete_unused_stacks(&(stacks.list), map, \
			nbr_optimum_paths(map, &(stacks.list), &s));
		ft_population_distrib(map, &(stacks.list), 1);
		ft_print_movements(map, &(stacks.list));
	}
}
