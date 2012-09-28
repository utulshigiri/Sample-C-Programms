#include<stdio.h>
#include<stdlib.h>

void binary_search(int arr[], int low, int high, int number, int *a)
{
	int temp;
	int mid = ((low + high) / 2) ;
	printf("Index is %d", mid);
	if(low>high)
	{
		printf("Number %d not present... \n",number);
		return;
	}
	if(arr[mid] == number)
	{
	        printf("Index of %d is %d\n", number,  mid) ;
		*a = mid;
		return;
	}
	else if(arr[mid] > number)
	{
		binary_search(arr, low, mid-1, number, a);
	}
	else
	{
		binary_search(arr, mid+1, high, number, a);
	}
}

int main(int argc, char * argv[])
{

	int arr[] = {1, 2, 2, 2, 2, 2, 2, 3, 3, 4} ;
	int i, num;
	int a= 0,  b=0;
	for(i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	} 

        printf("\n");
	printf("Enter the number\n");
	scanf("%d", &num);
	printf("%d\n", num);
	binary_search(arr, 0, 9, num, &a);

	if(arr[a-1]==num)
	{
	        binary_search(arr, 0, a-1, num, &b);
	}	
        printf("%d\n", a);
        printf("%d\n", b);

	return 0;
}
