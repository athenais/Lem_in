/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_queue.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:46:39 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/11 12:32:30 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_QUEUE_H
# define LEM_IN_QUEUE_H

# include <stdint.h>
# include <lem_in_list.h>

typedef struct	s_queue
{
	t_listhead	list;
	uint32_t	key;
	uint32_t	ant;
}				t_queue;

void			ft_copy_list(t_listhead *dest, t_listhead *source);
t_queue			*ft_queue_node(uint32_t key) __attribute__((always_inline));
t_queue			*ft_queue_entry(t_listhead *ptr) __attribute__((always_inline));

#endif
