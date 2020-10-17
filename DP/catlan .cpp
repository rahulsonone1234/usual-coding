#include<bits/stdc++.h>
using namespace std;

int catlan(int n)
{
    if(n<=1)
    return 1;
    
    int res=0;
    for(int i=0;i<n;i++)
    {
        res+=catlan(i)*catlan(n-i-1);
    }
    
    return res;
}
int main()
{
    int n;
    cin>>n;
    cout<<catlan(n)<<endl;
    return 0;
}

/////////////////////////////////////////////////////////////////DP
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007


int catlan(int n)
{
   int arr[n+1];
   arr[0]=arr[1]=1;
   for(int i=2;i<=n;i++)
   {
       arr[i]=0;
       for(int j=0;j<i;j++)
       {
           arr[i]= (arr[i]+(arr[j]*arr[i-j-1])%mod)%mod;
       }
   }
   return arr[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<catlan(n)<<endl;
    return 0;
}
////////////////////////////////////////////////////////////////////Binomial Coefficient
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int binomial_coeff(int n,int k)
{
    int res=1;
    if(k>n-k)
    k=n-k;
    
    for(int i=0;i<k;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}

int catlan(int n)
{
   int a=binomial_coeff(2*n, n);
   return a/(n+1);
}
int main()
{
    int n;
    cin>>n;
    cout<<catlan(n)<<endl;
    return 0;
}

////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007


int catlan(int n)
{
   int res=1;
   for(int i=1;i<=n;i++)
   {
       res*=(4*i-2);
       res/=(i+1);
   }
   return res;
}
int main()
{
    int n;
    cin>>n;
    cout<<catlan(n)<<endl;
    return 0;
}
