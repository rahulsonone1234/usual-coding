//A very important application of Bellman Ford is to check if there is a negative //cycle in the graph,

//Time Complexity of Bellman Ford algorithm is relatively high O(v.e), in case e=v^2,O(v^3) .

#include<bits/stdc++.h>
using namespace std;

void bellmanford(int graph[][3] ,int v ,int e ,int src)
{
	//initalize the distance with infinity
	int dis[v];
	for(int i=0;i<v;i++)
	{
		dis[i]=INT_MAX;
	}

	//initialize the source with 0
	dis[src]=0;
	//Relax all edges v-1 times
	for(int i=0;i<v-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			if(dis[graph[j][0]]+graph[j][2]<dis[graph[j][1]])
			{
				dis[graph[j][1]]=dis[graph[j][0]]+graph[j][2];
			}

		}
	}
	//checks for the negative weight cycle
	for(int i=0;i<e;i++)
	{
		int x=graph[i][0];
		int y=graph[i][1];
		int w=graph[i][2];
		if(dis[x]!=INT_MAX&&dis[x]+w<dis[y])	
		{
			cout<<"Graph Contains Negative Edge Cycle";
		}
	}
	cout<<"Vertex Distance from source"<<endl;
	for(int i=0;i<v;i++)
	{
		cout<<i<<"\t\t"<<dis[i]<<endl;
	}
}
int main()
{
	int v=5;
	int e=8;
	int graph[][3]={{0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},{3,2,5},{3,1,1},{4,3,-3}};

	bellmanford(graph ,v ,e ,0);
	return 0;
}
