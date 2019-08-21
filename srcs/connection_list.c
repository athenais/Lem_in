/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 23:15:36 by abrunet           #+#    #+#             */
/*   Updated: 2019/05/23 12:06:43 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_bug.h>
#include <lem_in_compiler.h>
#include <lem_in_algorithm.h>

static t_edges		*make_node(uint32_t hashkey)
{
	t_edges			*new;

	if (!(new = (t_edges *)malloc(sizeof(t_edges))))
		return (NULL);
	new->key = hashkey;
	new->way = open_way;
	new->next = NULL;
	return (new);
}

uint8_t				key_idx(uint32_t h1, uint32_t h2, t_map *map, t_edges *new)
{
	t_edges			*tmp;

	tmp = map->hashtab[h1]->adjc;
	while (tmp != NULL)
	{
		if (UNLIKELY(tmp->key == h2))
		{
			free((void *)new);
			return (ft_puterror(DUPLINK));
		}
		if (!tmp->next)
		{
			tmp->next = new;
			return (EXIT_SUCCESS);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

uint8_t				add_connection(uint32_t hash1, uint32_t hash2, t_map *map)
{
	t_edges			*new;

	if (!(new = make_node(hash2)))
		return (EXIT_FAILURE);
	if (!map->hashtab[hash1]->adjc)
		map->hashtab[hash1]->adjc = new;
	else
		return ((key_idx(hash1, hash2, map, new)));
	return (EXIT_SUCCESS);
}
