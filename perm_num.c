#include <stdio.h>


void print(const int *v, const int size)
{
  int i;
  if (v != 0) 
  {
     for (i = 0; i < size; i++) 
     {
        printf("%4d", v[i] );
     }
     
     printf("\n");
  }
}


void visit(int *Value, int N, int k, int *arr)
{
  int j;
  for(j=0; j<N; j++)
	printf("%d", arr[j]);
  printf("\n");
  static level = -1;
  int i;
  level = level+1; 
  Value[k] = arr[level];

  printf("Value of val[%d] : %d   Level: %d\n", k, Value[k], level);
  if (level == N)
       print(Value, N);
  else
       	for (i = 0; i < N; i++)
          if(Value[i] == 0)
        	visit(Value, N, i, arr);
  level = level-1; 
  Value[k] = 0;
}


main()
{
  const int N = 3;
  int arr[]={4, 5, 3};
  int i;
  int Value[N];
  for (i = 0; i < N; i++) 
  {
    Value[i] = 0;
  }
  visit(Value, N, 0, arr);
}
