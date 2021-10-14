#include <stdio.h>

void printBytes(unsigned char *start, int len) {
	for (int i = 0; i < len; ++i)
	{
		printf("% .2x\n", start[i]);
	}
	printf("\n");
}


void printInt(int x){
	printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x){
	printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x){
	printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x){
	printBytes((unsigned char *) &x, sizeof(long));
}

void printLongLong(long long x){
	printBytes((unsigned char *) &x, sizeof(long long));
}

void printDouble(double x){
	printBytes((unsigned char *) &x, sizeof(double));
}

int main(int argc, char const *argv[])
{
	printInt((int) 255);
	printInt((int) -255);
	printFloat((float) 255);
	printShort((short) 255);
	printLong((long) 255);
	printLongLong((long long) 255);
	printDouble((double) 255);

	//The length of all of these prints are different
	//some of the binary values are also different
	//This is because different data types use different amount of bytes
	//Theres different formats for the different types
	return 0;
}
