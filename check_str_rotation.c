#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
        char *str1 = argv[1];
        char *str2 = argv[2];

        printf ("%s %s \n", str1, str2);


        int len = strlen(str1);
        if(len == strlen(str2) && len > 0)
        {
                char * buff = (char*)malloc(len*2+1);
                strcpy(buff,str1);
                strcat(buff,str1);
                if(strstr(buff,str2))
                {
                    printf("string is rotation.\n");
                    return 0;
                }
	}
        else  
        {
           	printf("String is not rotation\n");                 
                return 1;
        }
                
        
}

