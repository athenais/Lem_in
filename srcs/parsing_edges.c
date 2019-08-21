/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_edges.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:46:10 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/20 00:03:24 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_bug.h>
#include <lem_in_hash.h>
#include <lem_in_compiler.h>

uint8_t				ft_is_valid_for_algorithm(t_map *map)
{
	if (map->vertices < 2)
		return (ft_puterror(TOOSMALLFARM));
	else if ((!map->start_index || !map->end_index) && !map->hashtab[0]->name)
		return (ft_puterror(NOENTRY));
	return (EXIT_SUCCESS);
}

uint8_t				get_collision_key(uint32_t *hashkey, t_map *map,
										char *ptr, char const *buff)
{
	uint32_t		tmp;

	tmp = *hashkey;
	while (map->hashtab[*hashkey]->name != NULL)
	{
		if (buff != NULL)
		{
			if (!(ft_strncmp(map->hashtab[*hashkey]->name, buff, ptr - buff)))
				return (EXIT_SUCCESS);
		}
		else if ((ft_strcmp(map->hashtab[*hashkey]->name, ptr + 1)) == 0)
			return (EXIT_SUCCESS);
		(*hashkey)++;
		if (UNLIKELY(*hashkey == MAX_VERTICES))
			*hashkey = 0;
		if (UNLIKELY(*hashkey == tmp))
			return (ft_puterror(TOOBIG));
	}
	return (ft_puterror(NOROOM));
}

void				check_for_entry_edges(t_map *map, uint32_t h1, uint32_t h2)
{
	if (h1 == map->end_index || h2 == map->end_index)
		map->end_edges++;
	if (h1 == map->start_index || h2 == map->start_index)
		map->start_edges++;
}

uint8_t				get_connections(char const *buffer, char *ptr, t_map *map)
{
	uint32_t		hash1;
	uint32_t		hash2;

	if (!(ptr + 1))
		return (EXIT_FAILURE);
	hash2 = hash(ptr + 1);
	hash1 = hashn(buffer, ptr - buffer);
	if (get_collision_key(&hash1, map, ptr, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_collision_key(&hash2, map, ptr, NULL) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (add_connection(hash1, hash2, map))
		return (EXIT_FAILURE);
	if (add_connection(hash2, hash1, map))
		return (EXIT_FAILURE);
	check_for_entry_edges(map, hash1, hash2);
	return (EXIT_SUCCESS);
}

uint8_t				ft_parse_edges(t_map *map, char const *buffer)
{
	char			*ptr;

	if (UNLIKELY(map->vertices < 2))
		return (ft_puterror(TOOSMALLFARM));
	if (UNLIKELY((map->start_index == 0 || map->end_index == 0) \
		&& map->hashtab[0]->name == NULL))
		return (ft_puterror(NOENTRY));
	if (LIKELY((ptr = ft_strrchr(buffer, '-'))))
	{
		if (get_connections(buffer, ptr, map))
			return (EXIT_FAILURE);
	}
	else
		return (ft_puterror(UNKCOMM));
	return (EXIT_SUCCESS);
}
