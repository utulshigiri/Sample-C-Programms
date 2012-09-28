/* Randomized Quick Sort */

#include<stdio.h>
#include<stdlib.h>

int n;

void swap(int *a, int *b)

{
	int x;
	x = *a;
	*a = *b;
	*b = x;
}

void quicksort(int s[], int l, int h)

{
	int p; /* index of partition */

	if ((h - l) > 0) 
	{
		p = partition(s, l, h);
		quicksort(s, l, p - 1);
		quicksort(s, p + 1, h);
	}

}

int partition(int s[], int l, int h)

{
	int i;
	int p; /* pivot element index */
	int firsthigh; /* divider position for pivot element */

	p = l + (rand() % (h - l + 1));
	swap(&s[p], &s[h]);
	firsthigh = l;

	for (i = l; i < h; i++)
		if(s[i] < s[h]) 
		{
			swap(&s[i], &s[firsthigh]);
			firsthigh++;
		}
	swap(&s[h], &s[firsthigh]);
	
	return(firsthigh);

}

void main()

{

	int s[20],i;

	printf("\nRandomized Quick Sort");

	printf("\nEnter the no. of elementsi: ");
	scanf("%d", &n);

	printf("\nEnter the elements one by one: ");

	for(i=0;i<n;i++)
		scanf("%d",&s[i]);

	quicksort(s,0,n-1);

	printf("\nAfter sorting : \n");

	for(i=0;i<n;i++)
		printf("%d\t",s[i]);

	printf("\n");
}
