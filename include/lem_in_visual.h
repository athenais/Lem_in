/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_visual.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:27:33 by abrunet           #+#    #+#             */
/*   Updated: 2019/06/19 14:28:09 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_VISUAL_H
# define LEM_IN_VISUAL_H

# include <lem_in.h>

# ifndef LEM_IN_LIST_H
#  include <lem_in_list.h>
# endif

# undef PATH
# define PATH		"../visual/"

# undef DATA
# define DATA		"../visual/data.txt"

# undef PATHS
# define PATHS		"../visual/paths.txt"

# undef ANTS
# define ANTS		"../visual/ants.txt"

void				write_shortest_to_file(t_map *map, t_listhead *head);
uint8_t				write_paths_to_file(t_map *map, t_listhead *head);

#endif
