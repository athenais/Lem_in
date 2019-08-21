/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_bug.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 22:07:23 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/09 12:30:25 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_BUG_H
# define LEM_IN_BUG_H

# include <stdint.h>

/*
**	Color codes used for displaying errors
*/
# define C_RED			"\x1B[41m"
# define C_NONE			"\033[0m\n"

/*
**	Error messages
*/
# define BADNAME		"Invalid room name"
# define MEMERR			"Memory allocation failure"
# define TOOBIG			"Number of rooms out of domain, adjust MAX_VERTICES"
# define UNKCOMM		"Command line not well formatted"
# define DUPLICATE		"Room has already been defined"
# define OUTDOMAIN		"Numerical argument out of domain"
# define NONNUM			"Non-numeric value encountered"
# define EMAXVERT		"MAX_VERTICES is out of domain"
# define MEMFULL		"No space left on device"
# define BADINPUT		"Invalid argument"
# define EMPTYLINE		"Empty line"
# define INVALIDFMT		"File type is not supported"
# define DUPLINK		"Connection already exists"
# define NOROOM			"Room doesn't exist"
# define TOOSMALLFARM	"Ant farm doesn't have enough rooms"
# define NOENTRY		"No ##start and/or ##end"
# define DEADEND		"No possible path to ##end"

uint8_t					ft_puterror(char const *error);

#endif
