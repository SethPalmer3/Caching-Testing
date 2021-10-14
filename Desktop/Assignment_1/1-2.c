#include <stdio.h>

unsigned replace(unsigned x, int i, unsigned char b){
	//effectivly multiplies i by 8
	unsigned offset = i << 3;
	//reversed masked to keep good part of x
	unsigned mask = 0xFF << offset;
	//flip the mask again
	mask = ~mask;

	//put b in the right spot
	unsigned new_b = b << offset;

	x = mask & x;
	return new_b | x; 
}

int main(int argc, char const *argv[])
{
	unsigned repl_test_1 = replace(0x12345678, 3, 0xAB);
	unsigned repl_test_2 = replace(0x12345678, 0, 0xAB);
	printf("%x\n", repl_test_1);
	printf("%x\n", repl_test_2);
	return 0;
}