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

#include "libft_malloc.h"

t_block		*request_space(t_zone *zone, t_block *last, size_t size)
{
	t_block		*block;

	if (MAP_FAILED == (block = mmap(0, size + BLOCK_SIZE,
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	if (last)
		last->next = block;
	else
		zone->base = block;
	block->size = size;
	block->next = NULL;
	block->free = 0;
	if (zone->type != LARGE_TYPE)
		zone->remaining -= size + BLOCK_SIZE;
	return (block);
}
