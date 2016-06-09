#include <stdio.h>

#include "libft_malloc.h"

int main(void)
{
	printf("Testing...\n");
	char *toto = (char *)malloc(50);
	char *titi = (char *)malloc(5000);

	show_alloc_mem();
	return (0);
}
