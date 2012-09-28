#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_longest_pali()

int check_palin(char str[])
{
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
}

int main(int argc, char *argv[])
{
	char str[20] = "ujwalaw";

	int res = check_palin(str);

	if(res)
		printf("Not Palindrome");

	return 0;
}
