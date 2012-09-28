#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void * my_strrev(char *input)
{
	char *start, *end;
	start = end = input;
	while(*end != '\0')
		end++;

	end--;
	while(end > start)
	{
		*start = *start + *end;
		*end = *start - *end;
		*start = *start - *end;
		end--;
		start++;
	}
}

void other_strrev(char *a, char *b)
{
	char *p, *q;
	p = b;
	q = a + strlen(a) - 1;
	while(q >= a)
	{
		(*p++) = (*q--);
	}
	printf("%s\n", b);
}

int main(int argc, char *argv[])
{
	char *str = "right";
	char str1[10];

	printf("%s\n", str);

	//my_strrev(str);
	other_strrev(str, str1);

//	printf("%s\n", str1);
	return 0;
}
