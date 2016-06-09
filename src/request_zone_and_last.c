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

void		request_zone_and_last(t_zone **zone, t_block **last, size_t size)
{
	t_zone	*base_zone;

	*zone = NULL;
	*last = NULL;
	base_zone = get_base();
	if (!base_zone)
	{
		*zone = create_zone(size);
		set_base(*zone);
	}
	else
	{
	}
	(void)size;
}
