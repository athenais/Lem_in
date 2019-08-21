/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:01:27 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/14 23:24:52 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <lem_in_bug.h>
#include <lem_in_parsing.h>
#include <lem_in_compiler.h>
#include <unistd.h>

static void				ft_parse_command_lines(t_map *map, char const *buffer)
{
	if (ft_strcmp(buffer, "##start") == 0)
		map->entry_point = 1;
	else if (ft_strcmp(buffer, "##end") == 0)
		map->entry_point = 2;
	else if (ft_strncmp(buffer, "##color=", 8) == 0)
		if (ft_isdigit(buffer[8]) && buffer[8] - '0' < 8 && buffer[9] == 0)
			map->visual |= ((buffer[8] - '0') << 0x10u);
}

static uint8_t			ft_parse_ants(t_map *map, char const *buffer)
{
	register uint16_t	index;

	index = 0;
	while (buffer[index])
	{
		if (UNLIKELY(ft_isdigit(buffer[index]) == 0))
			return (ft_puterror(BADINPUT));
		else
			map->population = map->population * 10 + buffer[index] - '0';
		if (UNLIKELY(map->population >> 0x19u))
			return (ft_puterror(OUTDOMAIN));
		index++;
	}
	if (UNLIKELY(map->population == 0))
		return (ft_puterror(OUTDOMAIN));
	return (EXIT_SUCCESS);
}

static inline uint8_t	ft_get_funptr_index(char const *buffer)
{
	uint32_t			index;

	if (LIKELY((index = ft_word_count(buffer)) > 0 && index < 4))
		return (index - 1);
	return (0);
}

/*
** 	Analyzes returned 'buffer' string by get_next_line to find
**	out if we're dealing with a room definition, a tube one
**	or the total amount of ants. It then proceeds to the
** 	corresponding function.
*/

static uint8_t			ft_parse_buffer(t_map *map, char const *buffer)
{
	static uint8_t		index;
	uint8_t				(*funptr[3])(t_map *, char const *);

	funptr[0] = &ft_parse_ants;
	funptr[1] = &ft_parse_edges;
	funptr[2] = &ft_parse_vertices;
	if (UNLIKELY(buffer == NULL || !buffer[0]))
		return (ft_puterror(EMPTYLINE));
	if (buffer[0] == '#')
	{
		if (buffer[1] == '#')
			ft_parse_command_lines(map, buffer);
	}
	else if (UNLIKELY(index == 0))
		return ((funptr[index++])(map, buffer));
	else if ((index = ft_get_funptr_index(buffer)) != 0)
	{
		if ((funptr[index])(map, buffer) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	else
		return (ft_puterror(UNKCOMM));
	return (EXIT_SUCCESS);
}

/*
** 	Reads standard input. If file descriptor 0 is redirection (isatty == 0),
**	checks if redirection is towards a regular file (S_ISREG)
**	or of the pipe kind (S_ISFIFO).
**	The lines are stored in a circular linked list and are freed while being
**	displayed on the standard ouput.
*/

uint8_t					ft_read_std_input(t_map *map)
{
	t_input				lines;
	char				*buffer;
	static char			*string;

	if (UNLIKELY(ft_isvalidformat(STDIN_FILENO) == EXIT_FAILURE))
		return (ft_puterror(INVALIDFMT));
	if (UNLIKELY((string = ft_strnew(1)) == NULL))
		return (ft_puterror(MEMERR));
	ft_list_init_head(&(lines.list));
	while (ft_readline(&string, &buffer) > 0)
	{
		ft_list_add_tail(&(ft_make_node(buffer)->list), &(lines.list));
		if (ft_parse_buffer(map, buffer) == EXIT_FAILURE)
			return (ft_parsing_panic(&(lines.list), string));
	}
	ft_variadic_freeing(2, (void *)buffer, (void *)string);
	if (UNLIKELY(map->vertices < 2))
	{
		ft_parsing_panic(&(lines.list), NULL);
		return (ft_puterror(TOOSMALLFARM));
	}
	map->start_edges = (uint32_t)ft_min(map->start_edges, map->end_edges);
	ft_safe_print_and_free(&(lines.list));
	return (EXIT_SUCCESS);
}
