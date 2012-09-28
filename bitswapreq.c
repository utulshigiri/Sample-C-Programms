#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{
	int a = (int)atoi(argv[1]);
	int b = (int)atoi(argv[2]);
	int c, count = 0;

	printf("%d %d\n", a, b);

	for(c = a^b ; c != 0; c = c>>1)
	{
		count += c & 1;
	}

	printf("Number of bits required : %d \n", count);
	return 0;
}
