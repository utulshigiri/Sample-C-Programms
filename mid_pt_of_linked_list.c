#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;


Node* find_mid(struct node *head)
{
	struct node *slow, *fast;
	slow = fast = head;

	while( fast !=NULL  && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main(int argc, char *argv[])
{
	struct node *a, *head, *b;
	b = (struct node*)malloc(sizeof(struct node));
	int i;
	head=NULL;

	int j =100;
	for(i=0;i<7;i++)
	{
		a = (struct node*)malloc(sizeof(struct node));
		a->data = j-i;
		a->next = head;
		printf("%d ", a->data);
		head = a;
	}
	a = head;
	b = find_mid(a);
	printf("\nMid point is %d\n", b->data);

	return 0;
}
