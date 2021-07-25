#include "libftprintf.h"

int	main(void)
{
	int num = 0;
	int num2 = 0;

	//num = ft_printf("FAKE-> %0*.*d \n", 21, 10, -101);
	//num2 = printf("REAL-> %0*.*d \n", 21, 10, -101);
	num += ft_printf("FAKE-> %.x\n", 0);
	num2 += printf("REAL-> %.x\n", 0);


	printf("FAKE-> %d\n", num);
	printf("REAL-> %d\n", num2);
	system("leaks a.out");
	

	return (0);
}
