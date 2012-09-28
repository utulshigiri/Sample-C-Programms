#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
   int data;
   struct node* next;
}node;

node* reverse(node* p)
{
   node *q  = NULL;
   while(p != NULL)
   {
      node *r = p->next;
      p->next = q;
      q = p;
      p = r;
   }
   return q;
}

void find_mid(node *p)
{
	node *fast, *slow;
	fast = slow = p;
	if(p==NULL)
		return;
	else
	{
		while(fast->next!=NULL && fast->next->next!=NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		printf("Mid point is %d\n",slow->data);
	}
}

void print_list(node* root) {
  while (root) {
    printf("%d\t", root->data);
    root = root->next;
  }
  printf("\n");
}

int main(void)
{
   int i;
   node *a, *b, *c, *d, *e;

   a = malloc(sizeof(struct node));
   b = malloc(sizeof(struct node));
   c = malloc(sizeof(struct node));
   d = malloc(sizeof(struct node));
   e = malloc(sizeof(struct node));
   
   a->data = 5;
   b->data = 7;
   c->data = 9;
   d->data = 11;
   e->data = 13;

   a->next = b;
   b->next = c;
   c->next = d;   
   d->next = e;
   e->next = NULL;

   printf("Linked list is:\n");
   print_list(a);

   c = reverse(a);

   printf("Reversed Linked list is:\n");
   print_list(c);

   find_mid(c);
   return 0;
}
