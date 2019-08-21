/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_unused_paths.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:39:05 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/19 14:28:46 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_stacks.h>
#include <lem_in_visual.h>
#include <lem_in_compiler.h>

static inline void		ft_delete_all(t_listhead *head)
{
	while (head != head->next)
	{
		ft_list_del(&(ft_stack_entry(head->next)->path->list));
		free((void *)ft_stack_entry(head->next)->path);
		ft_list_pop(head->next);
	}
}

static inline void		ft_keep_shortest(t_listhead *head)
{
	t_listhead			*tmp;
	t_listhead			*position;

	position = head->next->next;
	while (position != head)
	{
		tmp = position->next;
		ft_list_del(&(ft_stack_entry(position)->path->list));
		free((void *)ft_stack_entry(position)->path);
		ft_list_pop(position);
		position = tmp;
	}
}

static inline void		ft_keep_n_paths(t_listhead *head, uint16_t nb)
{
	t_listhead			*tmp;
	t_listhead			*position;
	register uint16_t	index;

	ft_list_del(&(ft_stack_entry(head->next)->path->list));
	free((void *)ft_stack_entry(head->next)->path);
	ft_list_pop(head->next);
	position = head;
	index = 0;
	while (LIKELY(position->next != head) && index++ <= nb)
		position = position->next;
	position = position->next;
	while (position != head)
	{
		tmp = position->next;
		ft_list_del(&(ft_stack_entry(position)->path->list));
		free((void *)ft_stack_entry(position)->path);
		ft_list_pop(position);
		position = tmp;
	}
}

void					ft_delete_unused_stacks(t_listhead *head, t_map *map,
												uint16_t nb)
{
	if (UNLIKELY(nb == 0))
		ft_delete_all(head);
	else if (nb == 1)
	{
		if (map->visual & VISUAL)
			write_shortest_to_file(map, head);
		ft_keep_shortest(head);
	}
	else if (LIKELY(nb > 1))
		ft_keep_n_paths(head, nb);
}
