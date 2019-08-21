/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_vertices.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:05:00 by thflahau          #+#    #+#             */
/*   Updated: 2019/05/23 12:06:13 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_bug.h>
#include <lem_in_hash.h>
#include <lem_in_compiler.h>

static inline void	set_entry(uint64_t entry, t_map *map, uint64_t hashkey)
{
	if (entry == 1)
		map->start_index = hashkey;
	else if (LIKELY(entry == 2))
		map->end_index = hashkey;
	map->entry_point = 0;
}

static uint8_t		ft_coordinate(char const *buffer)
{
	if (UNLIKELY(buffer[0] == ' '))
		return (EXIT_FAILURE);
	else if (UNLIKELY(ft_is32bits(ft_atoi_parsing(&buffer)) == 0))
		return (EXIT_FAILURE);
	else if (UNLIKELY((*(buffer + 1) && *(buffer + 1) == ' ')))
		return (EXIT_FAILURE);
	else if (UNLIKELY(ft_is32bits(ft_atoi_parsing(&buffer)) == 0))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
**  Retrieves array index where to put the room's name then
**  iterates until an empty spot is found (if needed).
*/

static uint8_t		ft_add_to_hashtable(t_map *map, char const *name)
{
	uint8_t			index;
	uint64_t		hashkey;

	index = 0;
	hashkey = hash(name);
	while (hashkey < MAX_VERTICES && map->hashtab[hashkey]->name != NULL)
	{
		if (UNLIKELY(!ft_strcmp(map->hashtab[hashkey++]->name, name)))
			return (ft_puterror(DUPLICATE));
		if (UNLIKELY(hashkey == MAX_VERTICES))
			hashkey = index++;
		else if (UNLIKELY(index > 1))
			return (ft_puterror(TOOBIG));
	}
	if (UNLIKELY(map->entry_point))
		set_entry(map->entry_point, map, hashkey);
	map->hashtab[hashkey]->name = name;
	map->hashtab[hashkey]->key = hashkey;
	map->vertices++;
	return (EXIT_SUCCESS);
}

/*
**	Initial check of room definition.
*/

uint8_t				ft_parse_vertices(t_map *map, char const *buffer)
{
	char			*name;
	uint16_t		index;

	index = 0;
	if (UNLIKELY(buffer[0] == 'L' || buffer[0] == ' '))
		return (ft_puterror(BADNAME));
	while (ft_isblank(buffer[index]) == 0)
		index++;
	if (UNLIKELY(buffer[index] != ' '))
		return (ft_puterror(BADNAME));
	if (UNLIKELY(!(name = ft_strsub(buffer, 0, index))))
		return (ft_puterror(MEMERR));
	if (UNLIKELY(ft_add_to_hashtable(map, name) == EXIT_FAILURE))
		return (ft_variadic_freeing(1, (void *)name));
	if (UNLIKELY(ft_coordinate(buffer + index + 1) == EXIT_FAILURE))
		return (ft_puterror(BADINPUT));
	return (EXIT_SUCCESS);
}
