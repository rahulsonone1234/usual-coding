#include<bits/stdc++.h>
using namespace std;
int res[1001][1001];
int mcmrecursive(int a[], int i, int j)
{
    if(i>=j)
        return 0;
        
    if(res[i][j]!=-1)
        return res[i][j];
        
    int min=INT_MAX;
    int k;
    for(k=i;k<=j-1;k++)
    {
        int tmp=mcmrecursive(a,i,k)+mcmrecursive(a,k+1,j)+(a[i-1]*a[k]*a[j]);
        
        if(tmp<min)
        {
            min=tmp;
        }
    }
    return res[i][j]= min;
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
    memset(res,-1,sizeof(res));
    cout<<mcmrecursive(a, 1, n-1)<<endl;
    return 0;
}
