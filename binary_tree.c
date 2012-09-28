#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct btree{
        int data;
	int visited;
        struct btree *right;
        struct btree *left;
};


int search(struct btree *root, int num)
{
        if(root == NULL) { return 1; }         //IMP STATE
        else
        {
                if(root->data == num) { return 0; }
                else
                {
                        if(root->data < num)         // DONT CHECK NULL CONDITION HERE.. JUST RETURN
                        {
                                return search(root->right, num);
                        }
                        else
                        {
                                return  search(root->left, num);
                        }
                }
        }
}

void dfs(struct btree *root)
{
	if(root)
	{
		printf("%d ", root->data);
		root->visited = 1;
	}

	if(root->left)
	{
		if(root->left->visited == 0)
			dfs(root->left);
	}

	if(root->right)
	{
		if(root->right->visited == 0)
			dfs(root->right);
	}
}

void print_level(struct btree *root, int n)
{
	if(root == NULL) {return;}
	if(n==1)
		printf(" %d ",root->data);
	else
	{
		print_level(root->left, n-1);
		print_level(root->right, n-1);
	}
}


int max_height(struct btree *root)
{
	if(root == NULL)
		return 0;
	else
		return 1 + max(max_height(root->left),max_height(root->right));

}

void print_level_order(struct btree *root)
{
	int height = max_height(root);
	int i;
	for(i=1;i<=height;i++)
	{
		print_level(root,i);
		printf("\n");
	}
}

struct btree* insert(struct btree *root, struct btree *n)
{
	if(root == NULL)
		return n;
	else
	{
		if(n->data <= root->data)
			root->left = insert(root->left, n);
		else if(n->data > root->data)
			root->right = insert(root->right, n);
	}
	return root;
}

void print_pre(struct btree *root)
{
	if(root == NULL){return;}
	printf("%d ",root->data);
	print_pre(root->left);
	print_pre(root->right);
}


void print_tr(struct btree *root)
{
        if(root == NULL){return;}
        print_tr(root->left);
        printf("%d ", root->data);
        print_tr(root->right);
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
        return (1 + max(max_depth(root->left), max_depth(root->right)));
}

int min_depth(struct btree *root)
{
        if(root == NULL) {return 0;}
        return (1 + min(min_depth(root->left), min_depth(root->right)));
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

int main()
{
        struct btree *n1, *root;
        int i;
        int a[10]={25,32,24,38,12,6,49,35,10,28};
//        int a[10] = {5, 3, 7, 2, 4, 1, 6, 8, 9, 4};
        root = NULL;

        for(i=0;i<10;i++)
        {
                n1 = malloc(sizeof(struct btree));
                n1->data = a[i];
                n1->right = n1->left = NULL;
                root = insert(root, n1);
        }

        printf("Tree data : ");
        print_pre(root);

        i = search(root,a[8]);
        if(i!=0)
                printf("\nNumber not found..\n");
        else
                printf("\nNumber %d  found..\n",a[8]);

	i = isBalanced(root);

	print_level_order(root);

	dfs(root);
        return 0;
}

