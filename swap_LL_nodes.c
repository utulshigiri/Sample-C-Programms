#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* first = NULL;

struct node* makenode(int a)
{
	struct node* tmp = NULL;
	tmp = malloc(sizeof(struct node));
	tmp->data = a;
	tmp->next = NULL;
	return tmp;
}

void display()
{
	if(first == NULL)
		return;

	struct node* tmp = first;
	do
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	while(tmp != NULL);
}

void swap()
{
	int count = 0;
	struct node* tmp = first;

	if(tmp == NULL)
		return;
	do
	{
		count++;
		if(count % 2 == 1)
		{
			if(tmp->next == NULL)
			continue;
			int _tmp = tmp->data;
			tmp->data = tmp->next->data;
			tmp->next->data = _tmp;
		}
		tmp = tmp->next;
	}
	while(tmp != NULL);
}

int main()
{

printf("HEllo\n");
first = makenode(1);
first->next = makenode(2);
first->next->next = makenode(3);
first->next->next->next = makenode(4);
first->next->next->next->next = makenode(5);
first->next->next->next->next->next = makenode(6);

printf("Before swapping\n");
display();
swap();
printf("\nAfter swapping\n");
display();
printf("\nHEllo\n");
return 0;
}
