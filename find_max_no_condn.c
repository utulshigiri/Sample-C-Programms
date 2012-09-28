#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b)
{
	int d = a - b;
	int k = (d >> 31) & 1 ; 
	int max = a - k *d ;
	return max;
}


int main(int argc, char *argv[])
{
	int a = (int)atoi(argv[1]) ;
	int b = (int)atoi(argv[2]);
	int c;

	c = max(a,b);
	printf("Maximum of %d and %d is %d\n", a, b, c);
	return 0; 
}
