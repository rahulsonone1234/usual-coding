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
    for(int k=1;k<=f;k++)
    {
        int tmp=1+max(eggdrop(e-1, k-1), eggdrop(e, f-k));
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
