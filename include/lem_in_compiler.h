/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_compiler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 22:05:06 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/03 10:22:19 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_COMPILER_H
# define LEM_IN_COMPILER_H

/*
**	These builtins instruct the compiler which branch of the program
**	is more likely to be executed.
*/
# ifdef __GNUC__
#  define CCV (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#  if CCV > 29600
#   define LIKELY(x)		__builtin_expect(!!(x), 1)
#   define UNLIKELY(x)		__builtin_expect(!!(x), 0)

#  else
#   define LIKELY(x)		(x)
#   define UNLIKELY(x)		(x)
#  endif

# else
#  error "Your compiler does not use the C preprocessor, try using GCC"
# endif

#endif
