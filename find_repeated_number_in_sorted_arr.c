#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
//	int arr[] = {1};
//      int arr[] = {1,1};
//      int arr[] = {};
        int arr[] = {1,2,3,4,5,6,7,7,8};
//      int arr[] = {1,1,2,3,4,5,6,7,8};
//      int arr[] = {1,2,3,4,5,5,6,7,8};
//        int arr[] = {1,2,2,3,4,5,6,6,7};

	int arrlen=0;
	int i=0;

	arrlen = sizeof(arr)/sizeof(int);
	printf("Array length is %d.\n", arrlen);
	for(i=0; i< arrlen; i++)
	{
		if(arr[i] == arr[i+1])
		{
			printf("Repeated number is %d.\n", arr[i]);
			//break;
		}
	}

	if(i==arrlen+1)
	{
		printf("No number is repeated.\n");
	}

	return 0;
}
