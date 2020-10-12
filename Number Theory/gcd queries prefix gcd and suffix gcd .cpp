#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int pre[100005];
int suf[100005];

int gcd(int a, int b){
    if(b==0)
    return a;
    
    return gcd(b, a%b);
}
int main()
{
    int t, q, n, l, r;
    cin>>t;
    
    while(t--){
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        
        pre[0]=suf[n+1]=0;
        for(int i=1;i<=n;i++)
        {
            pre[i]=gcd(arr[i], pre[i-1]);
        }
        
        for(int i=n;i>=1;i--)
        {
            suf[i]=gcd(arr[i], suf[i+1]);
        }
        while(q--)
        {
            cin>>l>>r;
            cout<<gcd(pre[l-1], suf[r+1])<<endl;;
        }
    }
    return 0;
}
