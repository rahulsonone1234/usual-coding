#include<stdio.h>
#include<stdlib.h>

int fib(int no)
{
    if(no==0)
        return 0;
    else if(no==1)
            return 1;
        else
            return fib(no-1)+fib(no-2);

}

int main()
{
    int no,fib1,fib2,fib3,i;

    printf("\nEnter no");
    scanf("%d",&no);
    //fib1=0;
    //fib2=1;

  //  printf("%d %d",fib1,fib2);
  /*  for(i=no-2;i>0;i--)
    {
        fib3=fib1+fib2;
        fib1=fib2;
        fib2=fib3;

        printf(" %d ",fib3);
    }*/
    for(i=0;i<no;i++)
        printf(" %d",fib(i));
   // printf(" %d ",fib);

}
