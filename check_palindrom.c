#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	char str[20] = "ujwalawju";

	int len = strlen(str);
	int i;

	for(i=0; i<=(len/2); i++)
	{
		printf("Checking for %c and %c \n", str[i], str[len-i-1]);
		if (str[i] != str[len-i-1])
		{
			printf("NOT PALINDROME\n");
			return 1;
		}
	}
	printf("String length is %d and its PALINDROME\n",len );
	

	return 0;
}
