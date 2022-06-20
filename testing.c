#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
	int i, j;
	unsigned long	test = ULONG_MAX;
	void	*ptr = &test;

	i = printf("%x\n", test);
	j = ft_printf("%x\n", test);
	printf("and printf returns %i, while mine returns %i", i, j);
	return 0;
}
