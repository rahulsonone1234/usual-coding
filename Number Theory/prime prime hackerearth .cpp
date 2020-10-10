#include<bits/stdc++.h>
using namespace std;

int arr[1000001];
int pp[1000001];
void sieve()
{   
    int maxN=1000000;
    
    for(int i=0;i<=maxN;i++)
    {
        arr[i]=1;
    }
    arr[0]=arr[1]=0;
    for(int i=2;i*i<=maxN;i++)
    {
        if(arr[i]==1)
        {
            for(int j=i*i;j<=maxN;j+=i)
            {
                arr[j]=0;
            }
        }
    }
    int cnt=0;
    
    for(int i=0;i<=maxN;i++)
    {
        if(arr[i]==1)
        {
            cnt++;
        }

        if(arr[cnt]==1)
        {
            pp[i]=1;
        }
        else
        {
             pp[i]=0;
        }
    }
    for(int i=0;i<=maxN;i++)
    {
        pp[i]+=pp[i-1];
    }

}
int main()
{
    sieve();
    int l ,r, t;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        cout<<pp[r]-pp[l-1]<<endl;
    }
    return 0;
}
