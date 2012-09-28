#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
	int a[10]={2, 3, 4, 6, 8, 9, 10, 3, 7, 11};
	int i,j,m,n,p;
	int count = 0;
	for (i=0,j=0;i<10;i++,j++)
	{
		printf(" %d ", a[i]);
	}

	m = (int)atoi(argv[1]);
	n = (int)atoi(argv[2]);
	printf("\nGiven Numbers is %d and given sum is %d",m,n);

	p = n-m;

	printf("\nTotal array elements are %d",j);

	for (i=0;i<j;i++)
	{
		if ((m==a[i] && count == 0))
		{	
			count++;
			continue;
		}
		if(a[i] == p)
		{
			printf("\nSUCCESS : Number found is %d\n", a[i]);
			return 0 ;
		}
	}
	printf("\nFAIL : No candidate number is found.\n");
	return 0;
}
