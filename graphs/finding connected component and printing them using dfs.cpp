#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
int visited[1000001]={0};

void dfs(int s)
{
    visited[s]=1;
    cout<<s<<" ";
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
    for(int i=1;i<=e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }   
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
            cout<<endl;
        }
    }
    return 0;
}
