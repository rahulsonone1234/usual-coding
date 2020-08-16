#include<stdio.h>
#include<stdlib.h>
#include"iostream"
using namespace std;

int gcd(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;

        return gcd(b,a%b);
}

int main()
{
        int no1,no2;
        cin>>no1;
        cin>>no2;
        cout<<gcd(no1,no2);
       return 0;
}
