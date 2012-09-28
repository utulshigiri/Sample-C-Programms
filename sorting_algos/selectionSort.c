#include<stdio.h>
#include<stdlib.h>

void selectionSort(int numbers[], int array_size)
{
  int i, j;
  int min, temp;

  for (i = 0; i < array_size-1; i++)
  {
    min = i;
    for (j = i+1; j < array_size; j++)
    {
      if (numbers[j] < numbers[min])
        min = j;
    }
    temp = numbers[i];
    numbers[i] = numbers[min];
    numbers[min] = temp;
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

        printf("\n");

        selectionSort(arr,len);

        for(i=0; i<len; i++)
                       printf("%d ",arr[i]);

        return 0;
}

