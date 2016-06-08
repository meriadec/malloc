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

# define META_SIZE sizeof(t_block)

# define TINY_TYPE 0
# define SMALL_TYPE 1
# define LARGE_TYPE 2

# define TINY_SIZE 64
# define SMALL_SIZE 128
# define LARGE_SIZE 512

typedef struct		s_block
{
	size_t			size;
	struct s_block	*next;
	int				free;
}					t_block;

typedef struct		s_zone
{
	size_t			size;
	struct s_block	*next;
	int				free;
}					t_zone;

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();

t_block				*request_space(t_block *last, size_t size);
t_block				*find_free_block(t_block **last, size_t size);
void				*get_base(void);
void 				set_base(void *val);

#endif
