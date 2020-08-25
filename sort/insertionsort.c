#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	int i,j,flag;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(i=1;i<n;i++)
    {
        j=i-1;
        flag=a[i];
        while(j>=0&&a[j]>flag)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=flag;
    }
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
			cout<<j+1<<" ";
		}
	}
	return 0;
}
