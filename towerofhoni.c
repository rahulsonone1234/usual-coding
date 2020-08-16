#include<stdio.h>
#include<stdlib.h>

void tower_of_honoi(int no,char from_rod,char to_rod,char aux_rod)       //from_rod=a
{                                                                        //to_rod=c
   if(no==1)                                                                //aux_rod=b
    {
        printf("\n Move disk 1 from rod %c to %c",from_rod,to_rod);
        return;
    }
    tower_of_honoi(no-1,from_rod,aux_rod,to_rod);
    printf("\n Move disk %d from rod %c to %c",no,from_rod,to_rod);
    tower_of_honoi(no-1,aux_rod,to_rod,from_rod);

}
int main()
{
    int no;
    printf("\n Enter no of discs");
    scanf("%d",&no);
    tower_of_honoi(no,'a','c','b');
    return 0;
}
