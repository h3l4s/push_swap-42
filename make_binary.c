#include "push_swap.h"

long	make_binary(int decimalnum)
{
	long	binarynum;
	int		rem;
	int		temp;

	binarynum = 0;
	temp = 1;
	while (decimalnum != 0)
	{
		rem = decimalnum % 2;
		decimalnum = decimalnum / 2;
		binarynum = binarynum + rem * temp;
		temp = temp * 10;
	}
	return (binarynum);
}
