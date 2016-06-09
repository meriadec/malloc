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

#include "libft_malloc.h"

static t_block		*get_last_block(t_zone *zone)
{
	t_block	*block;

	block = zone->base;
	while (block && block->next)
		block = block->next;
	return (block);
}

static t_zone		*get_available_zone(t_zone *base, size_t size)
{
	if (!base)
		return (NULL);
	while (base && (base->type == LARGE_TYPE
				|| base->remaining < size + BLOCK_SIZE))
		base = base->next;
	return (base);
}

void				request_zone_and_last(t_zone **zone,
		t_block **last, size_t size)
{
	*last = NULL;
	*zone = get_available_zone(get_base(), size);
	if (!*zone)
		*zone = create_zone(size);
	else
		*last = get_last_block(*zone);
}
