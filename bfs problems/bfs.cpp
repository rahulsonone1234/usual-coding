#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000];
bool visited[100001]={false};
int level[100001];
int k;
void bfs(int s/*,int k*/)
{
	queue<int>q;
	q.push(s);
	level[s]=1;
	visited[s]=true;
	while(!q.empty())
	{
		int p=q.front();
		cout<<p<<" ";
		q.pop();
		for(int i=0;i<adj[p].size();i++)
		{
			if(visited[adj[p][i]]==false)
			{
				q.push(adj[p][i]);
				level[adj[p][i]]=level[p]+1;
				//if(level[adj[p][i]]==x)
				//{
				//	k++;
				//}
				visited[adj[p][i]]=true;	
			}
		} 
	}
}
int main()
{
		
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" :";
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	bfs(1);
	cout<<endl;
	for(int i=1;i<=n;i++)cout<<level[i]<<" ";
	return 0;
	
}


