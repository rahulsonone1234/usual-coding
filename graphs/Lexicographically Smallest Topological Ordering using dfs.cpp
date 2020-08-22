/*
this can be easily done using with bfs but if some one wants to try with dfs.
there is two imp point
1 sort all adjacency list in descending order.
2 when apply calling of dfs function iterate vertes in descending order.
*/



#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
int visited[100005]={0};

stack<int>stk;

void dfs(int s)
{
    visited[s]=1;
    for(auto it=adj[s].begin();it!=adj[s].end();it++)
    {
        if(!visited[*it])
        {
            dfs(*it);
        }
    }
    stk.push(s);
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
    for(int i=0;i<=n;i++)
    {
        sort(adj[i].begin(),adj[i].end(),greater<int>());
    }
    for(int i=n;i>0;i--)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}
