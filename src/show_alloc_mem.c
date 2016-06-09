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

char		*zone_label(int zone_type)
{
	if (zone_type == 0)
		return ("TINY");
	else if (zone_type == 1)
		return ("SMALL");
	else
		return ("LARGE");
}

void		show_address(void *e)
{
	char	a[16];
	char	res[9];
	int		n;
	int		c;

	ft_memcpy(a, "0123456789ABCDEF", 16);
	ft_bzero(res, 9);
	ft_memset(res, '0', 8);
	c = 7;
	n = (int)e;
	res[c--] = a[n % 16];
	while ((int)(n /= 16) > 0 && c > -1)
		res[c--] = a[n % 16];
	ft_putstr("0x1");
	ft_putstr(res);
}

void		show_block(t_block *block)
{
	show_address(block + BLOCK_SIZE);
	ft_putstr(" - ");
	show_address(block + BLOCK_SIZE + block->size);
	ft_putstr(" : ");
	ft_idiot_putnbr(block->size);
	ft_putstr(" octets\n");
}

void		show_zone(t_zone *zone)
{
	t_block	*block;

	ft_putstr(zone_label(zone->type));
	ft_putstr(" : ");
	show_address(zone);
	ft_putstr("\n");
	block = zone->base;
	while (block)
	{
		show_block(block);
		block = block->next;
	}
}

void		show_alloc_mem(void)
{
	t_zone		*zone;

	zone = (t_zone *)(get_base());
	while (zone)
	{
		show_zone(zone);
		zone = zone->next;
	}
}
