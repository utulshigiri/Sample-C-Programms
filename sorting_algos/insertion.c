#include<stdio.h>
#include<stdlib.h>

void insertionSort(int numbers[], int array_size)
{
  int i, j, index;

  for (i=1; i < array_size; i++)
  {
    index = numbers[i];
    j = i;
    while ((j > 0) && (numbers[j-1] > index))
    {
      numbers[j] = numbers[j-1];
      j = j - 1;
    }
    numbers[j] = index;
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

        insertionSort(arr,len);

        for(i=0; i<len; i++)
                       printf("%d ",arr[i]);

        return 0;
}

