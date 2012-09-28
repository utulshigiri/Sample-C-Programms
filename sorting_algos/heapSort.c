#include<stdio.h>
#include<stdlib.h>

void siftDown(int numbers[], int root, int bottom);

void heapSort(int numbers[], int array_size)
{
  int i, temp;

  for (i = (array_size / 2)-1; i >= 0; i--)
    siftDown(numbers, i, array_size);

  for (i = array_size-1; i >= 1; i--)
  {
    temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i-1);
  }
}


void siftDown(int numbers[], int root, int bottom)
{
  int done, maxChild, temp;

  done = 0;
  while ((root*2 <= bottom) && (!done))
  {
    if (root*2 == bottom)
      maxChild = root * 2;
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;

    if (numbers[root] < numbers[maxChild])
    {
      temp = numbers[root];
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else
      done = 1;
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

        heapSort(arr,len);

        for(i=0; i<len; i++)
                       printf("%d ",arr[i]);

        return 0;
}

