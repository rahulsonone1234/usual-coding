#include<bits/stdc++.h>
using namespace std;

int eggdrop(int e, int f)
{
    if(f==0||f==1)
    return f;
        
    if(e==1)
    return f;
    
    int min=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int tmp=1+max(eggdrop(e-1, k-1), eggdrop(e, f-k));
        if(tmp<min)
        {
            min=tmp;
        }
    }
    return min;
}
int main()
{
    int e;
    int f;
    cin>>e>>f;
    cout<<eggdrop(e, f)<<endl;
    return 0;
}
