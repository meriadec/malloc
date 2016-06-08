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

void	*malloc(size_t size)
{
	t_block		*block;
	t_block		*last;

	if (size <= 0)
		return (NULL);
	if (!get_base())
	{
		block = request_space(NULL, size);
		if (!block)
			return (NULL);
		set_base(block);
	}
	else
	{
		last = get_base();
		block = find_free_block(&last, size);
		if (!block)
		{
			block = request_space(last, size);
			if (!block)
				return (NULL);
		}
		else
			block->free = 0;
	}
	return (block + 1);
}
