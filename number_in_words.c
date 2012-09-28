#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

   char *a[] = {"One", "Two", "Three" ,"Four", "Five", "Six", "Seven", "Eight", "Nine"};
   char *b[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen"};
   char *c[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty"};

   int d = (int)atoi(argv[1]);
 
   printf("Entered number is %d\n", d);

   if (d >0  && d <10)
   {
      printf("Number is %s\n", a[d-1]);
   }
  

   if(d >= 11 && d <20)
   {
      printf("\nNumber is %s\n", b[d-10]);
   }


   if((d==10) || (d >= 20 && d<100))
   {
      int m = d/10;
      int n = d - (m*10);
      printf("str [1] = %d %d\n", m, n);
  
      if (m==1)
      {
             printf("Number is %s\n",b[0]);
	     return 0;
      } 
      char *q = malloc(sizeof(char*));
      strcpy(q, c[m-2]);
      
      if (n ==0)
      {
        printf("\n%s\n", q);
        return 0;
      }
      strcat(q," ");
      strcat(q, a[n-1]);

      printf("\n %s\n", q);
   }

   return 0;


}
