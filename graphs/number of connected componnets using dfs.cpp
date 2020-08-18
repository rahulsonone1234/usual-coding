#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
bool visited[100001];

void dfs(int s)
{
    visited[s]=true;
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
    int cmp=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            dfs(i);
            cmp++;
        }
    }
    cout<<"Number of connected components: "<<cmp<<endl;
    return 0;
}
