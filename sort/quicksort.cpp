#include<bits/stdc++.h>
using namespace std;
void swap(int *p, int *q)
{
    int r;
    r=*p;
    *p=*q;
    *q=r;
}
void pivot(int *a, int l, int r)
{
    if(a[l]>a[r])
        swap(a+l, a+r);
}
int partition(int *a, int l, int r)
{
    int i=l+1,j=r,k=a[l];
    do
    {
        do ++i;
        while(a[i]<k);
        do --j;
        while(a[j]>k);
        
        if(i<j)
            swap(a+i, a+j);
    }while(i<j);
    
    swap(a+j, a+l);
    return j;
}
void quicksort(int *a, int l,int r)
{
    if(l<r)
    {
        pivot(a ,l ,r);
        int k=partition(a, l, r);
        quicksort(a, l, k-1);
        quicksort(a, k+1, r);
    }
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
    
    quicksort(a, 0, n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
