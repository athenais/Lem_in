/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:31:26 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/11 12:34:12 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in_stacks.h>
#include <lem_in_compiler.h>

static inline void		ft_copy_queue(t_listhead *dest, t_listhead *source)
{
	t_queue				*node;
	t_listhead			*position;

	position = source;
	while ((position = position->next) != source)
		if ((node = ft_queue_node(ft_queue_entry(position)->key)) != NULL)
			ft_list_add_tail(&(node->list), dest);
}

void					ft_copy_list(t_listhead *dest, t_listhead *source)
{
	t_stack				*node;
	t_listhead			*position;

	position = source;
	ft_free_stacks(dest);
	ft_list_init_head(dest);
	ft_stack_entry(dest)->ant = ft_stack_entry(source)->ant;
	while ((position = position->next) != source)
	{
		if (LIKELY((node = ft_stack_node()) != NULL))
		{
			if ((node->path = (t_queue *)malloc(sizeof(t_queue))))
				ft_list_init_head(&(node->path->list));
			node->ant = ft_stack_entry(position)->ant;
			node->size = ft_stack_entry(position)->size;
			ft_copy_queue(&(node->path->list), \
				&(ft_stack_entry(position)->path->list));
			ft_list_add_tail(&(node->list), dest);
		}
	}
}
