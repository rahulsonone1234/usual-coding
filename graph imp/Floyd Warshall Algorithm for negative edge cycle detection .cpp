#include<bits/stdc++.h>
using namespace std;
#define v 4
#define inf 99999

void floydwarshall(int graph[][v])
{
	int dist[v][v],i,j,k;
	for( i=0;i<v;i++)
	{
		for( j=0;j<v;j++)
		{
			dist[i][j]=graph[i][j];
		}
	}
	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(dist[i][j]==inf)
			cout<<"inf"<<" ";
			else
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<v;i++)
	{
	    if(dist[i][i]<0)
	    {
	        cout<<" Negative Cycle is Present "<<endl;
	        return;
	    }
	    else
	    {
	        cout<<" No Cycle "<<endl;
	        return
	    }
	}
}
int main()
{
	int graph[v][v]={{0 ,5 ,inf, 10},
			 {inf ,0 ,3 ,inf},
			 {inf ,inf ,0 ,1},
			 {inf ,inf ,inf ,0}
			};
	floydwarshall(graph);
	return 0;
}
