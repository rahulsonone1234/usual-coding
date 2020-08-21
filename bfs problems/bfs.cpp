#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
int visited[100001]={false};

queue<int>q;

void bfs(int s)
{
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        cout<<tmp<<" ";
        for(auto it=adj[tmp].begin();it!=adj[tmp].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it]=true;
                q.push(*it);
            }
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
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bfs(i);
        }
    }
    return 0;
}
