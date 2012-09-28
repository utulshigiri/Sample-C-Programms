#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int n = (int)atoi(argv[1]);
	printf("Number \t : %d\n", n);
	
	int a[5];
	int m=10, i,j;

	for(j=4; n>10; j--)
	{
		i = n % m;
		a[j] = i;
		n = n/m;
	}
	a[j] = n;

	printf("Array form : ");
	for(i=0;i<5;i++)
		 printf("%d ",a[i]);	

	printf("\n New string : ");	
	int len = 5 / 2;

	if(a[len-1] < a[len+1])
		a[len-1] = a[len+1];
	else
	  	a[len+1] = a[len-1];

	for(i=(len+2),j=(len-2);i<5;i++,j--)
	{
		a[i] = a[j];
		printf("%d",a[i]);
	}
	int sum = 0;
	m = 1;	

	printf("Hello");
        for(i=4;i<=0;i--)
	{
		printf("Here");
		sum = sum + a[i] * m ;
                printf("%d ",a[i]);
		m = m * 10;
	}
	
	printf("\n Next bigger palindrome = %d\n", sum);

	return 0;
}
