// Given a array.. having N numbers. all numbers except one is repeated even number of times and a single element is repeated for odd number of
//times. Find that odd number..


#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	printf("Enter array of 11 elements\n");

	int a[11]; 
	int i;

	for (i=0 ; i<11; i++)
	{
		scanf("%d",&a[i]);
	}

	printf("\nArray is \n");
        for (i=0 ; i<11; i++)
        {
                printf("%d ",a[i]);
        }

	int v = 0;
        for (i=0 ; i<(sizeof(a)/sizeof(int)); i++)
        {
        	v ^= a[i];
	}

	printf("\nOdd number is %d\n\n", v);
	return 0;
}
