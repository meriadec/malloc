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

t_block		*request_space(t_block *last, size_t size)
{
	t_block		*block;
	int 		prot = PROT_READ | PROT_WRITE;
	int 		flags = MAP_ANON | MAP_PRIVATE;

	if (MAP_FAILED == (block = mmap(0, size + META_SIZE, prot, flags, -1, 0)))
		return (NULL);
	if (last)
		last->next = block;
	block->size = size;
	block->next = NULL;
	block->free = 0;
	return (block);
}
