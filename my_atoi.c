#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int my_atoi ( const char * s )
{
	int n = 0;
	if(!s) return 0;
	while(*s)
	{
		if(*s< '0' || *s> '9')
			return 0;
		n = n * 10 + *s - '0';
		s++;
	}
	return n;
}

int get_len_int(int n)
{
	int i=0;
	while(n>0)
        {
                n = n / 10;
                i++;
        }
	return i;
}

void  my_itoa(int a, char *str, int len)
{
//	str[len-1]='\0';
//	len--;
        while(a>0)
        {
		str[len] = (a % 10) + '0';
                a = a / 10;
		len--;
		printf("Int to char %c\n", str[len]);
        }
	printf("Int to char %s\n", str);
}

int main(int argc, char *argv[])
{
	char *str = "123";
	int i = my_atoi(str);
	printf("Char to int %d\n", i);

	int a = 598;
	int len_a = get_len_int(a);
	char str1[len_a+1];
	str1[len_a] = '\0';
	my_itoa(a, str1, len_a);
	printf("Int to char %s\n", str1);
	
	return 0;
}
