#include<bits/stdc++.h>
using namespace std;
//calculate a^n

int power(int a, int n)
{
    int res=1;
    
    while(n)
    {
        if(n%2==1)
        {
            res=res*a;
            n--;
        }
        else
        {
            a=a*a;
            n=n/2;
        }
    }
    return res;
}
int main()
{
    int a, n;
    cin>>a>>n;
    cout<<power(a, n)<<endl;
    return 0;
}
