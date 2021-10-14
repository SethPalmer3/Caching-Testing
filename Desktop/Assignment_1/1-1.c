#include <stdio.h>

unsigned combine(unsigned x, unsigned y){
	//mask part 1 and two
	unsigned x_mask = 0xFFFFFF00;
	unsigned y_mask = 0x000000FF;
	//apply mask
	x = x_mask & x;
	y = y_mask & y;

	return x | y;
}

int main(int argc, char const *argv[])
{
	unsigned comb_test_1 = combine(0x12345678, 0xABCDEF00);
	unsigned comb_test_2 = combine(0xABCDEF00, 0x12345678);
	printf("%x\n", comb_test_1);
	printf("%x\n", comb_test_2);

	return 0;
}