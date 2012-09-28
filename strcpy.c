#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int mystrlen(char *a)
{
	int count = 0;
	while(*a != '\0')
	{
		count++;
		a++;
	}
	printf("Count is %d\n", count);
	return count;
}

void mystrrev(char *a, char *b)
{
	char *p, *q;
	p = b;
	q = a + mystrlen(a) -1; 
	while(q >=  a)
	{	
		(*p++) = (*q--);
	}
	printf("Reverse : %s\n", b);
}

char* mystrcpy(char *a, char *b)
{
	char *p;
	p = a; 

	printf("String before copy : %s\n", b);	//q = a + mystrlen(a) - 1;

	while (*a)
	     a++;

	while((*a++) = (*b++))
	;	
        printf("Final after copy : %s\n", p);
		
	return p;
}

int main(int argc, char *argv[])
{
	char *str = argv[1];
	char str4[] = "ujwala";
	char str1[20];
	char str2[20];
	char *str3;

	printf("String : %s\n", str);	
	mystrrev(str,str1);

	str3 = (char*) malloc(strlen(str1)+1);

	str3 = mystrcpy(str2,str4);

	printf("Final : %s\n", str3);
//	mystrrev(str2,str1);
	return 0;

}
