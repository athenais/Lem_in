/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:04:23 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/20 00:11:01 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

# define MAX_VERTICES	8000

# define VISUAL			0x00000001u
# define COLORS			0x00010000u

typedef struct			s_edges
{
	int32_t				way;
	uint32_t			key;
	struct s_edges		*next;
}						t_edges;

typedef struct			s_vertices
{
	uint64_t			key;
	char const			*name;
	struct s_edges		*adjc;
	struct s_vertices	*prev;
}						t_vertices;

typedef struct			s_map
{
	uint32_t			start_index;
	uint32_t			end_index;
	uint32_t			population;
	uint32_t			start_edges;
	uint32_t			end_edges;
	uint32_t			vertices;
	uint32_t			entry_point;
	uint32_t			visual;
	struct s_vertices	*hashtab[MAX_VERTICES];
}						t_map;

/*
**	Parsing
*/
void					ft_print_usage(char const *name);
uint8_t					ft_read_std_input(t_map *map);
uint8_t					ft_is_valid_for_algorithm(t_map *map);
uint8_t					ft_parse_edges(t_map *map, char const *buffer);
uint8_t					ft_parse_vertices(t_map *node, char const *buffer);

/*
**	Memory
*/
int						ft_free_hashtable(t_vertices *hashtab[MAX_VERTICES]);
uint8_t					ft_initialize_hashtable(t_map *map);

/*
**	Lists
*/
uint8_t					add_connection(uint32_t h1, uint32_t h2, t_map *map);

/*
**	Algorithm
*/
double					func2(int32_t pop, int32_t diff, int32_t paths);
uint8_t					ft_breadth_first_search(t_map *map, int8_t *visited);
uint8_t					ft_algorithm(t_map *map);

#endif
