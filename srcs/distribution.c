/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:33:47 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/16 19:22:52 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_stacks.h>
#include <lem_in_visual.h>
#include <lem_in_compiler.h>

int32_t				nbr_optimum_paths(t_map *map, t_listhead *head, int32_t *s)
{
	int32_t			size;
	int32_t			diff;
	int32_t			sum;
	int32_t			var;
	t_listhead		*tmp;

	sum = 0;
	diff = 0;
	tmp = head->next;
	var = map->population;
	size = ft_stack_entry(tmp)->size - 2;
	while (tmp != head->prev)
	{
		diff += ft_stack_entry(tmp)->size - size - 2;
		sum = (int32_t)func2(map->population, diff, ++(*s));
		if (sum > var && (ft_stack_entry(head)->ant = var))
			return ((*s -= 1));
		tmp = tmp->next;
		var = sum;
	}
	ft_stack_entry(head)->ant = var;
	if (*s == 2 && var == sum)
		ft_stack_entry(head)->ant -= 1;
	return (*s);
}

void				ants_sup(uint32_t population, int32_t sum, t_listhead *head)
{
	int32_t			diff;
	t_listhead		*node;

	while ((uint32_t)sum > population)
	{
		node = head->next;
		while (node->next != head && ft_stack_entry(node->next)->ant > 0)
			node = node->next;
		diff = sum - population;
		if (((int32_t)(ft_stack_entry(node)->ant) - diff) < 0)
		{
			sum -= ft_stack_entry(node)->ant;
			diff = ft_abs(ft_stack_entry(node)->ant - diff);
			ft_stack_entry(node)->ant = 0;
		}
		else
		{
			ft_stack_entry(node)->ant -= diff;
			sum -= diff;
		}
	}
}

void				ants_min(uint32_t population, int32_t *sum,
												t_listhead *head)
{
	t_listhead		*node;

	while (*sum < (int32_t)population)
	{
		node = head;
		while ((node = node->next) != head && ft_stack_entry(node)->ant > 0)
		{
			ft_stack_entry(node)->ant += 1;
			*sum += 1;
			if (*sum == (int32_t)population)
				break ;
		}
	}
}

void				ants_to_path(int32_t ants, int *sum, int pop,
												t_listhead *head)
{
	int32_t			tmp;
	t_stack			*node;
	t_listhead		*ptr;

	ptr = head->next;
	tmp = (int32_t)ants;
	ft_stack_entry(ptr)->ant = ants;
	while ((ptr = ptr->next) != head && tmp > 0 && *sum <= pop)
	{
		node = ft_stack_entry(ptr);
		if ((tmp = ants - (node->size - ft_stack_entry(head->next)->size - 2)) \
			> 0)
		{
			if (head->next == ptr \
				&& node->size == ft_stack_entry(head->next)->size - 2 \
				&& pop % 2)
				tmp -= 1;
			node->ant = tmp;
			*sum += tmp;
		}
	}
}

void				ft_population_distrib(t_map *map, t_listhead *h, int8_t pat)
{
	int32_t			sum;
	int32_t			ants;

	ants = ft_stack_entry(h)->ant;
	ft_stack_entry(h->next)->ant = ft_stack_entry(h)->ant;
	sum = ants;
	if (h->next != h->prev)
	{
		ants_to_path(ants, &sum, map->population, h);
		ants_min(map->population, &sum, h);
		ants_sup(map->population, sum, h);
	}
	else
		ft_stack_entry(h->next)->ant = map->population;
	if (pat != 0 && (map->visual & VISUAL))
		write_paths_to_file(map, h);
}
