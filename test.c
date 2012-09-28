#include<stdlib.h>
#include<stdio.h>


void main()
{
struct
{
	int i;
}abc;

(*abc)->i=10;
printf("%d",abc.i);


}
