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

static void	idiotic_useless_norme_function_1(int *final_size, int *type,
		size_t *remaining, int val_to_assign_to_final_size)
{
	*final_size = val_to_assign_to_final_size;
	*type = LARGE_TYPE;
	*remaining = 0;
}

size_t		get_size_for(size_t size, int *type, size_t *remaining)
{
	int		content_size;
	int		final_size;
	int		page_size;

	page_size = getpagesize();
	content_size = size + ZONE_SIZE;
	if (content_size > SMALL_SIZE * page_size)
		idiotic_useless_norme_function_1(&final_size, type, remaining,
				page_size + page_size * (content_size / page_size));
	else if (content_size > TINY_SIZE * page_size)
	{
		final_size = SMALL_SIZE * page_size;
		*type = SMALL_TYPE;
		*remaining = final_size - SMALL_SIZE;
	}
	else
	{
		final_size = TINY_SIZE * page_size;
		*type = TINY_TYPE;
		*remaining = final_size - TINY_SIZE;
	}
	return (final_size);
}

t_zone		*create_zone(size_t size)
{
	t_zone		*zone;
	size_t		final_size;
	int			zone_type;
	size_t		remaining;

	final_size = get_size_for(size, &zone_type, &remaining);
	if (MAP_FAILED == (zone = mmap(0, final_size,
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	zone->type = zone_type;
	zone->remaining = remaining;
	zone->base = NULL;
	zone->next = NULL;
	printf("%lu\n", remaining);
	return (zone);
}
