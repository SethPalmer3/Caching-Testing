#include <stdio.h>

int oddBit(unsigned x){
	unsigned odd_mask = 0xAAAAAAAA;
	unsigned odd_check = odd_mask & x;

	int f_return = !(!odd_check);

	return f_return;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", oddBit(0x1));
	printf("%d\n", oddBit(0x2));
	printf("%d\n", oddBit(0x3));
	printf("%d\n", oddBit(0x4));
	printf("%d\n", oddBit(0xFFFFFFFF));
	printf("%d\n", oddBit(0xAAAAAAAA));
	printf("%d\n", oddBit(0x55555555));

	return 0;
}