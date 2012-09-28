#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mystrcpy(char *src, char *dest)
{
    while (*src != '\0')
    {
        (*dest++) = (*src++);
    }
    *dest = '\0';
}

int main(int argc, char * argv[])
{    

    char s1[] = "Ujwala";
    char s2[100];

    mystrcpy(s1,s2);
    printf("String A : %s \nString B %s\n", s1, s2);
    return 0;
}
