#include <stdio.h>
#include "libft_malloc.h"

int main(void)
{
	printf("Testing...\n");
	char *toto = (char *)malloc(54);
	printf("%s\n", toto);
	return (0);
}
