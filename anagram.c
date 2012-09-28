#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc , char *argv[])
{
	char arr[256];
	int i;
	char *s1 = argv[1];
	char *s2 = argv[2];

	if(strlen(s1) != strlen(s2))
	{
		printf("Strings %s and %s are NOT anagram..... \n", argv[1],argv[2]);
		return 1;
	}

	for (i=0; i<256;i++)	
		arr[i]=0;

        while  (*s1 != '\0')
	{
		arr[(int)*s1]++;
		s1++;
	}	

        while ( *s2 != '\0')
        {
		arr[(int)*s2]--;
		s2++;
        }

	for (i=0; i<256;i++)
	{
                if (arr[i] != 0)
		{
			printf("Strings %s and %s are NOT anagram..... \n", argv[1],argv[2]);
			return 1;
		}
	}
	printf("Strings %s and %s are anagram..... \n", argv[1],argv[2]);
	return 0;
} 
