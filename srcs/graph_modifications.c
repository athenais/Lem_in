/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:24:40 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/11 12:27:36 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_algorithm.h>

static inline void		ft_reset_adjacency_list(t_edges *head)
{
	while (head != NULL)
	{
		head->way = open_way;
		head = head->next;
	}
}

void					ft_reset_graph(t_map *map, uint32_t hk, uint32_t pk)
{
	t_edges				*ptr;
	register uint16_t	index;

	index = 0;
	while (index < MAX_VERTICES)
	{
		if (map->hashtab[index]->key != 0)
		{
			ptr = map->hashtab[index]->adjc;
			if (index == hk || index == pk)
			{
				while (ptr != NULL)
				{
					if (ptr->key == hk || ptr->key == pk)
						ptr->way = closed_way;
					else
						ptr->way = open_way;
					ptr = ptr->next;
				}
			}
			else
				ft_reset_adjacency_list(ptr);
		}
		++index;
	}
}
