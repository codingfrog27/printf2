#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
	int i, j;
	int	test = 9;
	void	*ptr = &test;

	i = printf("%u\n", test);
	j = ft_printf("%u\n", test);
	printf("and printf returns %i, while mine returns %i", i, j);
	return 0;
}
