/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidformat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 23:20:17 by thflahau          #+#    #+#             */
/*   Updated: 2019/06/14 23:24:36 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <sys/stat.h>

uint8_t					ft_isvalidformat(int fd)
{
	struct stat			informations;

	if (__builtin_expect(!!(fstat(fd, &informations) < 0), 0))
		return (EXIT_FAILURE);
	else if (!S_ISREG(informations.st_mode) && !S_ISFIFO(informations.st_mode))
		if (isatty(fd) == 0)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
