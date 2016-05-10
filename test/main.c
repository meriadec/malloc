#include <stdio.h>
#include "libft_malloc.h"

int main(void)
{
	printf("Testing...\n");
	char *toto = (char *)malloc(54);
	printf("%p\n", toto);
	return (0);
}
