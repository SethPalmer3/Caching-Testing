#include <stdio.h>

unsigned getOffset(unsigned address){
	unsigned mask = 0x000000ff;
	return address & mask;
}
unsigned getSet(unsigned address){
	unsigned mask = 0x0000000f;
	address >>= 8;
	return address & mask;
}
unsigned getTag(unsigned address){
	unsigned mask = 0x000fffff;
	address >>= 12;
	return address & mask;
}

int main(int argc, char const *argv[])
{
	unsigned addr1 = 0x12345678;
	unsigned addr2 = 0x87654321;
	printf("%x: offset: %x - tag: %x - set: %x\n", addr1, getOffset(addr1), getTag(addr1), getSet(addr1));
	printf("%x: offset: %x - tag: %x - set: %x\n", addr2, getOffset(addr2), getTag(addr2), getSet(addr2));

}