/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00000000000.0                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0000000 <000000@00.00>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 0000000           #+#    #+#             */
/*   Updated: 0000/00/00 00:00:00 by 0000000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft_malloc.h"

size_t		get_size_for(size_t size, int *type)
{
	int		content_size;
	int		final_size;
	int		page_size;

	page_size = getpagesize();
	content_size = size + ZONE_SIZE;
	if (content_size > SMALL_SIZE * page_size)
		final_size = page_size + ();
	else if (content_size > TINY_SIZE * page_size)
		final_size = SMALL_SIZE;
	else
		final_size = TINY_SIZE;
}

t_zone		*create_zone(size_t size)
{
	t_zone		*zone;
	size_t		final_size;
	int			zone_type;
	int 		prot = PROT_READ | PROT_WRITE;
	int 		flags = MAP_ANON | MAP_PRIVATE;

	final_size = get_size_for(size, &zone_type);
	printf("creating page of %lu\n", final_size);
	if (MAP_FAILED == (zone = mmap(0, final_size + ZONE_SIZE, prot, flags, -1, 0)))
		return (NULL);
	return (zone);
}
