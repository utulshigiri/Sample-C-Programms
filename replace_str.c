#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	char *str = argv[1];
	int i =0, j =0;
	char str1[20];

	printf("Original String : %s\n", str);
	while(*str != '\0')
	{
		if (*str == ' ')
		{
			str1[i] = '%'; 
			str1[i+1] = '2'; 
			str1[i+2] = '0'; 
			i = i+2;
		}
		else
		{
			str1[i] = *str;
		}

		i++;	
		str++;
	}

	printf("New string is : ");
	for(j = 0; j<i;j++)
	{
		printf("%c" ,str1[j]);
	}

	printf("\n");
	return 0;
}
