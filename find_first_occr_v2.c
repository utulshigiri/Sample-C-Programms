#include<stdio.h>
#include<stdlib.h>

void binary_search(int arr[], int low, int high, int number, int *a)
{
	int temp;
	int mid = ((low + high) / 2) ;
	
	if(low>high)
	{
		printf("Number %d not present... \n",number);
		return;
	}
	if(arr[mid] == number)
	{
		*a = mid;
	        while(arr[mid-1] == number)
	        {
        		*a = mid - 1;
			mid = mid - 1;        	
	        }
                printf("Index of %d is %d\n", number,  mid) ;

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

void binary_first_occr(int arr[], int low, int high, int number)
{
	int len = high + 1;
        int mid = (low + high) / 2;

	if(arr[low] == number)
	{
                printf("First occurance is %d\n.", low);
		return;
	}
		
	while((low+1) != high)
	{
		printf("Index is %d\n", mid);
		if(arr[mid] < number)
			low = mid;
		else
			high = mid;
		mid = (low + high) / 2;
	}

	if(high>len || arr[high]!=number)
		printf("Number not present\n");
	else
		printf("First occurance is %d\n.", high);
}


int binary_first_occr_rec(int arr[], int low, int high, int number)
{
        int len = high + 1;
        int mid, temp;

        if(arr[low] == number)
                return low;

	if(high < low)
		return -1;

	if(number > arr[high] || number < arr[low])
		return -1;

	mid = (low + high) / 2;
	if(arr[mid]==number)
	{
		temp = binary_first_occr_rec(arr, low, mid -1, number);
		if(temp == -1)
			return mid;
		else
			return temp;
	}
	else if(arr[mid] > number)
	{
		return binary_first_occr_rec(arr, low, mid-1, number );
	}
	else
	{
		return binary_first_occr_rec(arr, mid+1, high, number);
	}
}

int binary_last_occr_rec(int arr[], int low, int high, int number)
{
        int len = high + 1;
        int mid, temp;

        if(arr[high] == number)
                return high;

        if(high < low)
                return -1;

        if(number > arr[high] || number < arr[low])
                return -1;

        mid = (low + high) / 2;
        if(arr[mid]==number)
        {
                temp = binary_last_occr_rec(arr, mid+1, high, number);
                if(temp == -1)
                        return mid;
                else
                        return temp;
        }
        else if(arr[mid] > number)
        {
                return binary_last_occr_rec(arr, low, mid-1, number );
        }
        else
        {
                return binary_last_occr_rec(arr, mid+1, high, number);
        }
}


int main(int argc, char * argv[])
{
	int arr[] = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5, 6,6, 6, 6, 6, 6, 6, 6, 6, 6 , 6, 6, 6, 6,7,7,7,7,7,7,7,7,7,7,7,7,8} ;
	int i, num, len;
	int a = 0;

        len = sizeof(arr)/sizeof(int);
	for(i=0; i<len; i++)
	{
		printf("%d ", arr[i]);
	} 
	
	printf("\nEnter the number: ");
	scanf("%d", &num);
//	binary_search(arr, 0, 38, num, &a);
//	binary_first_occr(arr, 0, len - 1, num);

	printf("First occurance of %d in sorted array is %d\n",num, binary_first_occr_rec(arr, 0, len-1, num));
        printf("Last occurance of %d in sorted array is %d\n", num, binary_last_occr_rec(arr, 0, len-1, num));
	return 0;
}
