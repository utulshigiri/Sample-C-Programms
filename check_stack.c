#include<stdio.h>
#include<stdlib.h>


void foo(int *a)
{
	int b;
	if(&b > a)
	{
		printf("Stack is growing up.. \n");
	}	
	else
	{
		printf("Stack is growing down.. \n");
	}
}

int main()
{
	int a;
	foo(&a);
	printf("%p\n",  &a);
	return 0;
}
