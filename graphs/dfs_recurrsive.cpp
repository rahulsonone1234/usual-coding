#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
bool visited[100001]={false};

void dfs(int s)
{
    visited[s]=true;
    cout<<s<<" ";
    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
        {
            dfs(adj[s][i]);
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
	//can be used for disconnected graph as particular source is not given if particular source is given then it would work only for the connected one
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            dfs(i);
        }
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

vector < vector <int>>v(1000);
int visited[1000001]={0};

void dfs(int s)
{
	visited[s]=1;
	cout<<s<<" ";
	vector <int>::iterator it;
	for(it=v[s].begin();it!=v[s].end();++it)
	{
		if(!visited[*it])
			dfs(*it);
	}
}
int main()
{
	int n,e;
	cin>>n>>e;
	int x,y;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=0;i<n;i++)
	{
	    if(visited[i]==0)
	    {
	        dfs(i);
	    }
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
int visited[1000001]={0};

void dfs(int s)
{
    visited[s]=1;
    cout<<s<<" ";
   // vector<int>::iterator it;
    for(auto it=adj[s].begin();it!=adj[s].end();it++)
    {
        if(!visited[*it])
        {
            dfs(*it);
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }
    return 0;
}
