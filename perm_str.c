#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void swap(char *a, char *b)
{
        char temp = *b;
        *b = *a;
        *a = temp;
}


void perm(char *a, int m, int n)
{
	int i, j ;

	if(m==n)
		printf("String = %s\n",a);
	else
	{
		for(j=m;j<n;j++)
		{
			swap(&a[j],&a[m]);
			perm(a,m+1,n);
			swap(&a[m],&a[j]);
		}
	}	
}


int main(int argc, char *argv[])
{

	char *str = argv[1];
	
	int m= 0 ;
	printf("The string is %s\n", str);
	perm(str,m,strlen(str));
	return 0;
}
