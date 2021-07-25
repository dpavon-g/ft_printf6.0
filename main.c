#include "libftprintf.h"

int	main(void)
{
	int num = 0;
	int num2 = 0;

	//num = ft_printf("FAKE-> %0*.*d \n", 21, 10, -101);
	//num2 = printf("REAL-> %0*.*d \n", 21, 10, -101);
	num += ft_printf("FAKE-> %-*.2s| \n", 5, NULL);
	num2 += printf("REAL-> %-*.2s| \n", 5, NULL);


	printf("FAKE-> %d\n", num);
	printf("REAL-> %d\n", num2);
	system("leaks a.out");
	

	return (0);
}
