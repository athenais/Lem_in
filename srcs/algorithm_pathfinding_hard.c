/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_pathfinding_hard.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:41:46 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/19 23:10:17 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_list.h>
#include <lem_in_visual.h>
#include <lem_in_stacks.h>
#include <lem_in_compiler.h>
#include <lem_in_algorithm.h>

static void				ft_evaluate_solution(t_map *map, t_listhead *temp,
											uint32_t *min, t_listhead *ptr)
{
	int32_t				s;

	s = 1;
	ft_delete_unused_stacks(temp, map, nbr_optimum_paths(map, temp, &s));
	ft_population_distrib(map, temp, 0);
	if (ft_stack_entry(temp)->ant + ft_stack_entry(temp->next)->size < *min)
	{
		*min = ft_stack_entry(temp)->ant + ft_stack_entry(temp->next)->size;
		ft_copy_list(ptr, temp);
		ft_stack_entry(ptr)->ant = ft_stack_entry(temp)->ant;
		nbr_optimum_paths(map, ptr, &s);
		ft_population_distrib(map, ptr, 0);
	}
}

static inline void		ft_pathfinding(t_map *map, t_listhead *head)
{
	int8_t				visited[MAX_VERTICES];

	ft_fast_bzero(visited, MAX_VERTICES);
	while (ft_breadth_first_search(map, visited) == EXIT_SUCCESS)
	{
		ft_join_paths(map, head);
		if (UNLIKELY(ft_stack_entry(head->prev)->size == 2))
			ft_make_directed(map, head->prev);
		ft_update_visited_array(visited, head);
	}
}

static uint16_t			ft_unique_overlap(t_map *map, uint32_t **array,
										t_stack *stacks, t_stack *temp)
{
	int32_t				s;
	uint32_t			min;
	register uint16_t	index;

	s = 1;
	index = 0;
	min = UINT32_MAX;
	ft_pathfinding(map, &(temp->list));
	if (map->visual & VISUAL)
		write_shortest_to_file(map, &(temp->list));
	ft_evaluate_solution(map, &(temp->list), &min, &(stacks->list));
	ft_free_stacks(&(temp->list));
	if (stacks->list.next == stacks->list.prev)
		min = stacks->ant + ft_stack_entry(stacks->list.next)->size;
	else
		min = UINT32_MAX;
	while (array[index] != 0)
	{
		ft_reset_graph(map, array[index][0], array[index][1]);
		ft_pathfinding(map, &(temp->list));
		ft_evaluate_solution(map, &(temp->list), &min, &(stacks->list));
		ft_free_stacks(&(temp->list));
		++index;
	}
	return (min);
}

void					ft_advanced_pathfinding(t_map *map, uint32_t **tab,
												int32_t s)
{
	uint32_t			min;
	t_stack				stacks;
	t_stack				temp;
	register int16_t	i;
	register int16_t	j;

	j = -1;
	ft_list_init_head(&(temp.list));
	ft_list_init_head(&(stacks.list));
	min = ft_unique_overlap(map, tab, &stacks, &temp);
	ft_reset_graph(map, 0, 0);
	while (tab[++j] != 0 && (i = -1))
	{
		ft_reset_graph(map, tab[j][0], tab[j][1]);
		while (tab[++i] != 0)
		{
			ft_add_overlap(map, tab[i][0], tab[i][1]);
			ft_pathfinding(map, &(temp.list));
			ft_evaluate_solution(map, &(temp.list), &min, &(stacks.list));
			ft_free_stacks(&(temp.list));
		}
	}
	nbr_optimum_paths(map, &(stacks.list), &s);
	ft_population_distrib(map, &(stacks.list), 1);
	ft_print_movements(map, &(stacks.list));
}
