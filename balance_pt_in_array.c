#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
	int arr[]={1,2,3,4,6};
	int i=0;
	int arrlen=sizeof(arr)/sizeof(int);
	
	int forward_sum[arrlen], backward_sum[arrlen];

        for(i=0;i<arrlen;i++)
        {
		forward_sum[i]=0;
		backward_sum[i]=0;
        }

	forward_sum[0] = arr[0];
	backward_sum[arrlen-1] = arr[arrlen-1];
	

	for(i=1;i<arrlen;i++)
	{
		forward_sum[i] = forward_sum[i-1] + arr[i];
                backward_sum[arrlen-i-1] = backward_sum[arrlen-i] + arr[arrlen-i-1];
        }

	printf("\na[i]  left_sum[i] right_sum[i]\n");
        for(i=0;i<arrlen;i++)
        {
                printf("\n %d    %d    %d\n",arr[i], forward_sum[i], backward_sum[i]);

		if(forward_sum[i]==backward_sum[i])
			printf("Balance point is %d\n", arr[i]);

        }
	return 0;

}
