/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_algorithm.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 09:37:31 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/16 19:23:55 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_ALGORITHM_H
# define LEM_IN_ALGORITHM_H

# ifndef LEM_IN_H
#  include <lem_in.h>
# endif
# ifndef LEM_IN_STACKS_H
#  include <lem_in_stacks.h>
# endif

enum			e_vertex {
	unvisited_node,
	visited_node
};

enum			e_direction {
	closed_way,
	open_way
};

int				nbr_optimum_paths(t_map *map, t_listhead *head, int *p);
void			ft_advanced_pathfinding(t_map *map, uint32_t **tab, int32_t s);
void			ft_simple_pathfinding(t_map *map, uint32_t **tab, int32_t s);
void			ft_population_distrib(t_map *map, t_listhead *h, int8_t p);
void			ft_update_visited_array(int8_t *tab, t_listhead *head);
void			ft_reset_graph(t_map *map, uint32_t hk, uint32_t pk);
void			ft_add_overlap(t_map *map, uint32_t pk, uint32_t hk);
void			ft_print_movements(t_map *map, t_listhead *head);
void			ft_make_directed(t_map *map, t_listhead *head);
void			ft_update_graph(t_map *map, t_listhead *head);
void			ft_join_paths(t_map *map, t_listhead *head);
void			ft_reinitialize_graph(t_map *map);
void			ft_free_tab(uint32_t **tab);
uint8_t			ft_overlaps(t_map *map, uint32_t prev, uint32_t key);
uint32_t		**ft_search_for_overlaps(t_map *map);
uint32_t		**ft_initialize_tab(void);

#endif
