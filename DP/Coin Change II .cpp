#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum;
    cin>>sum;
    
    int res[sum+1];
    res[0]=0;
    
    for(int i=1;i<sum+1;i++)
        res[i]=INT_MAX;
        
    for(int i=1;i<=sum+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]<=i)
            {
                int sub_res=res[i-a[j]];
                if(sub_res!=INT_MAX && sub_res+1<res[i])
                res[i]=sub_res+1;
            }
        }
    }
    cout<<"Number of Subsets Present : "<<res[sum]<<endl;
    return 0;
}
