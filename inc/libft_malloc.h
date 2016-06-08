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

#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H
# include <stdlib.h>

# include <stdio.h>

# define BLOCK_SIZE sizeof(t_block)
# define ZONE_SIZE sizeof(t_zone)

# define TINY_TYPE 0
# define SMALL_TYPE 1
# define LARGE_TYPE 2

# define TINY_SIZE 1
# define SMALL_SIZE 2

typedef struct		s_block
{
	size_t			size;
	struct s_block	*next;
	int				free;
}					t_block;

typedef struct		s_zone
{
	int				type;
	size_t			remaining;
	t_block			*base;
	struct s_zone	*next;
}					t_zone;

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();

t_zone				*create_zone(size_t size);
void				request_zone_and_last(t_zone **zone, t_block **last, size_t size);
t_block				*request_space(t_block *last, size_t size);
t_block				*find_free_block(t_block **last, size_t size);

void				*get_base(void);
void 				set_base(void *val);

#endif
