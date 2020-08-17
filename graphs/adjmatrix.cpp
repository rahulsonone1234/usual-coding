#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, e;
	cin>>n>>e;
	int **edges=new int *[n];
	for(int i=1;i<=n;i++)
	{
		edges[i]=new int[n];
		for(int j=1;j<=n;j++)
		{
			edges[i][j]=0;
		}
	}
	for(int i=1;i<=e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<edges[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		delete[] edges[i];
	}
	delete []edges;

return 0;

}