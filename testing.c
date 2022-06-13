#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
	int i, j;
	void	*test;

	test = ULLONG_MAX;
	i = printf("%p\n", test);
	j = ft_printf("%p\n", test);
	printf("and printf returns %i, while mine returns %i", i, j);
	return 0;
}
