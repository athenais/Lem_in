/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:07:47 by thflahau          #+#    #+#             */
/*   Updated: 2019/05/26 12:58:48 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_PARSING_H
# define LEM_IN_PARSING_H

# include <lem_in_queue.h>

typedef struct				s_input
{
	t_listhead				list;
	char					*buffer;
}							t_input;

void						ft_safe_print_and_free(t_listhead *head);
t_input						*ft_input_entry(t_listhead *ptr);
t_input						*ft_make_node(char *buffer);
uint8_t						ft_free_lines(t_listhead *head);
uint8_t						ft_parsing_panic(t_listhead *head, char const *str);

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS		0
# endif

#endif
