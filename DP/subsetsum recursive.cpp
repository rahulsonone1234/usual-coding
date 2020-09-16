#include<bits/stdc++.h>
using namespace std;

int subsetsum(int a[], int n, int sum)
{
    if(sum==0)
    return true;
    if(n==0)
    return false;
    
    if(a[n-1]<=sum)
        return (subsetsum(a, n-1,sum-a[n-1])||subsetsum(a, n-1, sum));
    else
        return subsetsum(a, n-1, sum);
}
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
    
    if(subsetsum(a, n, sum))
        cout<<"subset is present"<<endl;
    else
        cout<<"subset is not present"<<endl;
    return 0;
}
