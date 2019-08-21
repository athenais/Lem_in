/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_stacks.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:03:49 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/16 19:07:43 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STACKS_H
# define LEM_IN_STACKS_H

# ifndef LEM_IN_QUEUE_H
#  include <lem_in_queue.h>
# endif
# ifndef LEM_IN_H
#  include <lem_in.h>
# endif

typedef struct		s_stack
{
	t_listhead		list;
	t_queue			*path;
	uint32_t		size;
	int32_t			ant;
}					t_stack;

void				ft_delete_unused_stacks(t_listhead *head, t_map *map,
											uint16_t nb);
void				ft_print_stack(t_map *map, t_listhead *head);
void				ft_free_stacks(t_listhead *head);
t_stack				*ft_stack_entry(t_listhead *ptr);
t_stack				*ft_stack_node(void) __attribute__((always_inline));

#endif
