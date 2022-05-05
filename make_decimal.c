#include "push_swap.h"

int	make_decimal(long long n)
{
	int	num;
	int	dec_value;
	int	base;
	int	temp;
	int	last_digit;

	num = n;
	temp = num;
	base = 1;
	dec_value = 0;
	while (temp)
	{
		last_digit = temp % 10;
		temp = temp / 10;
		dec_value += last_digit * base;
		base = base * 2;
	}
	return (dec_value);
}
