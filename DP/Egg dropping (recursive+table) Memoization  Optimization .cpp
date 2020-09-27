#include<bits/stdc++.h>
using namespace std;
int res[1001][1001];
int eggdrop(int e, int f)
{
    if(f==0||f==1)
    return f;
        
    if(e==1)
    return f;
    
    if(res[e][f]!=-1)
    return res[e][f];
    
    int min=INT_MAX;
     int low, high;
    for(int k=1;k<=f;k++)
    {
       
        if(res[e-1][k-1]!=-1)
        {
            low=res[e-1][k-1];   
        }
        else
        {
            low=eggdrop(e-1, k-1);
            res[e-1][k-1]=low;
        }
        
        if(res[e][f-k]!=-1)
        {
            high=res[e][f-k];   
        }
        else
        {
            high=eggdrop(e, f-k);
            res[e][f-k]=high;
        }
        
        int tmp=1+max(low, high);
        if(tmp<min)
        {
            min=tmp;
        }
    }
    return res[e][f]=min;
}
int main()
{
    int e;
    int f;
    cin>>e>>f;
    memset(res, -1, sizeof(res));
    cout<<eggdrop(e, f)<<endl;
    return 0;
}
