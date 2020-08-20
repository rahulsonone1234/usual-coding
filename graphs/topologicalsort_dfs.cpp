#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
int visited[1000001]={0};
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
    for(int i=0;i<n;i++)
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
