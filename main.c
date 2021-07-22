#include "libftprintf.h"

int	main(void)
{
	int num = 0;
	int num2 = 0;

	num = ft_printf("FAKE->  %06.d\n", 102);
	num2 = printf("REAL->  %06.d\n", 102);

	printf("FAKE-> %d\n", num);
	printf("REAL-> %d\n", num2);
	system("leaks a.out");
	

	return (0);
}
