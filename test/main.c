#include <stdio.h>

#include "libft_malloc.h"

int main(void)
{
	printf("Testing...\n");
	char *toto = (char *)malloc(54);
	char *tata = (char *)malloc(42);

	show_alloc_mem();
	return (0);
}
