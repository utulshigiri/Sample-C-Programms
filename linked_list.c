#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
	int data;
	struct node *next;
}node;

void insert(struct node *head, int n)
{
	struct node *n1;

	n1 = head;
        n1= malloc(sizeof(struct node *));
        n1->data = n;
	n1->next = NULL;


 	if (head == NULL)  // is there more elegant way of dealing with this? any idiom?
  	{
		head = n1;
		printf("Data inserted in null is : %d\n", head->data);
	}
	else
	{
		struct node *p;
		p = head;
		while(p->next != NULL)
			p = p ->next;

		p->next = n1;
	}

}

void print(struct node *head)
{
	printf("Inside print fun\n");
	while( head != NULL)
	{
		printf("%d \n", (head)->data);
		head = head->next ;
	}

}

void append(struct node **q,int num)
{ 	
	struct node *temp,*r;
	temp = *q;
	if(*q == NULL)
	{ 
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data=num;
		temp->next=NULL;
		*q=temp;
	}
	else
	{ 
		temp = *q;
		while(temp->next !=NULL)
		{ 	
			temp=temp->next;
		}
		r = (struct node *)malloc(sizeof(struct node));
		r->data=num;
		r->next=NULL;
		temp->next=r;
		}
}

	
int main(int argc, char *argv[])
{
	
	struct node *head, *curr, *n1;

	int n;

	head = NULL;
	printf("Enter element : ");
	scanf("%d",&n);

	append(&head,n);
	insert(head,5);
	insert(head,9);
	insert(head,10);

	insert(head,11);
	print(head);
	return 0;
}
