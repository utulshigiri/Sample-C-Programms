#include<stdio.h>
#include<stdlib.h>


void bubbleSort(int numbers[], int array_size)
{
  int i, j, temp;

  for (i = (array_size - 1); i >= 0; i--)
  {
    for (j = 1; j <= i; j++)
    {
      if (numbers[j-1] > numbers[j])
      {
        temp = numbers[j-1];
        numbers[j-1] = numbers[j];
        numbers[j] = temp;
      }
    }
  }
}

int main(int argc , char *argv[])
{
        int arr[1000];// = {31,11,651,112,145,171};

        int i, len;
        len=sizeof(arr)/sizeof(int);

        for(i=1000; i>0; i--)
        {
                arr[i]=i;
        }

        bubbleSort(arr,len);

        for(i=0; i<len; i++)
                       printf("%d ",arr[i]);
	printf("\n");
        return 0;
}

