#include<bits/stdc++.h>
using namespace std;

void simple_sieve(vector<int>&primes, int n)
{
    bool a[n+1];
    memset(a, true, sizeof(a));
    
    for(int i=2;i*i<=n;i++){
        if(a[i]==true){
            primes.push_back(i);
            for(int j=i*i;j<n;j+=i){
                a[j]=false;
            }
        }
    }
}
int main(){
    int l,r;
    cin>>l>>r;
    
    vector<int>primes;//primes for square root of R
    simple_sieve(primes, floor(sqrt(r))+1);
    
    int n=r-l+1;
    bool a[n+1];
    memset(a, false, sizeof(a));
    
    for(int i=0;i<primes.size();i++)
    {
        int tmp=floor(l/primes[i])*primes[i];
        
        if(tmp<l)
            tmp+=primes[i];
            
        if(tmp==primes[i])
            tmp+=primes[i];
            
        for(int j=tmp;j<=r;j+=primes[i])
        {
            a[j-l]=true;
        }
    }
    for(int i=l;i<=r;i++)
    {
        if(!a[i-l])
        {
            cout<<i<<" ";
        }
    }
 return 0;   
    
}
