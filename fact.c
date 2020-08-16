#include<stdio.h>
#include<stdlib.h>
/* uilse seujlk.jlnjn*/

int fact(int no)
{
   int fac;
   if(no==0)
        return 1;
   else
   {
       fac=no*fact(no-1);
        return fac;
   }
}

int main()
{
    int no;
    printf("\n Enter no");
    scanf("%d",&no);
    printf("\n %d",fact(no));

}
