#include<stdio.h>
#include<stdlib.h>


int non_rec_fifo(int n)
{
	int first=0, second=1, next;
	int i;
	for(i=0;i<n;i++)
	{
	        if(i == 1 || i == 0)
        	        next = i;
		else
		{	
			next = first + second;
			first = second;
			second = next;
		}
		
		printf("%d ", next);			
	}
}

int rec_fibo(int n)
{
	if(n == 1 || n == 0)
		return n;
	else
		return (rec_fibo(n-1) + rec_fibo(n-2));
}

int main(int argc, char *argv[])
{
	int n,i;
	scanf("%d", &n);
	printf("Entered Number is : %d\n", n );
	for(i=0;i<n;i++)
	{
		printf("%d ", rec_fibo(i));
	}
	printf("\n");

	non_rec_fifo(n);
	printf("\n");
	return 0;
}


