#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000];

vector<int>time_in(100001,0);
vector<int>time_out(100001,0);
vector<int>color(100001,0);
vector<bool>visited(100001,false);

int timer_dfs=0;
void dfs(int s)
{
	time_in[s]=timer_dfs++;
	visited[s]=true;
	cout<<s<<" ";
	color[v]=1;
	for(int i=0;i<adj[s].size();i++)
	{
		if(visited[adj[s][i]]==false)
		{
			dfs(adj[s][i]);
		}
	}
	color[v]=2;
	time_out[s]=timer_dfs++;
}

int main()
{
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	//	adj[b].push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			dfs(i);
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
	    cout<<"vertex :"<<i<<" ( "<<time_in[i]<<" "<<time_out[i]<<" ) "<<endl;
	}
	return 0;
}
