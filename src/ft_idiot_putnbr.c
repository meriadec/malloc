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

#include <stdlib.h>
#include "libft_malloc.h"

static int					dumb_get_length(int n, int negative)
{
	int		length;

	length = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	if (negative)
	{
		length++;
	}
	return (length);
}

static void					moron_norme_loop(char *str, int *n, int *length)
{
	while ((*n) != 0)
	{
		str[(*length)] = (*n) % 10 + '0';
		(*n) = (*n) / 10;
		(*length)--;
	}
}

static void					ft_idiot_itoa(int n, char *str)
{
	int		length;
	int		negative;

	if (n == -2147483648)
		ft_memcpy(str, "-2147483648", 11);
	else
	{
		negative = (n < 0) ? 1 : 0;
		n = (n < 0) ? -n : n;
		length = dumb_get_length(n, negative);
		if (str)
		{
			length--;
			str[length] = '0';
			moron_norme_loop(str, &n, &length);
			str[0] = negative ? '-' : str[0];
		}
	}
}

void						ft_idiot_putnbr(int n)
{
	char		str[255];

	ft_bzero(str, 255);
	ft_idiot_itoa(n, str);
	ft_putstr(str);
}
