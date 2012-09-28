#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct btree{
	int data;
	struct btree *right;
	struct btree *left;
};


int search(struct btree **root, int num)
{
	if(*root == NULL) { return 1; }  	//IMP STATE
	else
	{
		if((*root)->data == num) { return 0; }
		else
		{
			if((*root)->data < num)		// DONT CHECK NULL CONDITION HERE.. JUST RETURN
			{	
				return search(&(*root)->right, num);
			}
                        else
                        {
                                return  search(&(*root)->left, num);
                        }
		}
	}
}


int max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}


int min(int a , int b)
{
	if (a < b)
		return a;
	return b;
}

int max_depth(struct btree *root)
{
	if(root == NULL) {return 0;}
	int i= (1 + max(max_depth(root->left), max_depth(root->right)));
	printf("Max Depth : %d\n", i);
	return i;
}

int min_depth(struct btree *root)
{
	if(root == NULL) {return 0;}
	int i = (1 + min(min_depth(root->left), min_depth(root->right)));
	printf("MIN Depth : %d\n", i);
	return i;
}

int isBalanced(struct btree *root)
{
	if(max_depth(root)-min_depth(root) <= 1)
	{
		printf("Tree is balanced\n");
		return 0;
	}	
	else
	{
		printf("NOT BALANCED\n");
		return 1;
	}
}



void insert(struct btree **root, struct btree *n)
{
	if(*root == NULL)
	{
		*root= n;
	}
	else
	{
		if(n->data < (*root)->data)
			insert(&(*root)->left,n);
		else if(n->data >= (*root)->data)
			insert(&(*root)->right,n);
	}
}


void print_tr(struct btree *root)
{
	if(root == NULL){return;}
	print_tr(root->left);
	printf("%d ", root->data);
	print_tr(root->right);
}

int find_min(struct btree *root)
{
	while (root->left != NULL)
	{
		root= root->left;
	}
	return root->data;
}

int size(struct btree *root)
{
	if(root == NULL){return (0);}
	else
	{
		return(size(root->left) + 1 + size(root->right));
	}

}

int main()
{
	struct btree *n1, *root;
	int i;
//        int a[10]={25,32,24,38,12,6,49,35,10,28};
	int a[10] = {5, 3, 7, 2, 4, 1, 6, 8, 9, 0};
	root = NULL;

	for(i=0;i<10;i++)
	{
		n1 = malloc(sizeof(struct btree));
		n1->data = a[i];
		n1->right = n1->left = NULL;
		insert(&root,n1);		
	}

	printf("Tree data : ");
	print_tr(root);

        i = search(&root,38);
        if(i!=0)
                printf("\nNumber not found..\n");
	else
		printf("\nNumber %d  found..\n",38);

	i = search(&root,5);
        if(i!=0)
                printf("Number %d not found..\n", 5);
        else
                printf("Number %d  found..\n",5);

	printf("Min number is %d\n", find_min(root));	
	printf("SIZE of tree is %d\n", size(root));

	printf("IS tree balanced %d\n", isBalanced(root));
	return 0;
}
