#include "libftprintf.h"

int	main(void)
{
	int num = 0;
	int num2 = 0;

	num = ft_printf("FAKE-> %.3d\n", 2);
	num2 = printf("REAL-> %.3d\n", 2);

	printf("FAKE-> %d\n", num);
	printf("REAL-> %d\n", num2);
	system("leaks a.out");
	

	return (0);
}
