#include<stdio.h>


# define i 20
void fun();

main()
{
	printf("%d..",i);
	fun();
	printf("%d",i);
}
void fun()
{
#undef i 
#define i 30 
}

