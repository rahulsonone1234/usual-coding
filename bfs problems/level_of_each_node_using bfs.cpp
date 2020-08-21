#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
bool visited[1000001]={false};
queue<int>q;
int level[1000001]={0};

void bfs(int s)
{
    visited[s]=true;
    q.push(s);
    level[s]=0;
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
       // cout<<tmp<<" ";
        for(auto it=adj[tmp].begin();it!=adj[tmp].end();it++)
        {
            if(!visited[*it])
            {
                q.push(*it);
                visited[*it]=true;
                level[*it]=level[tmp]+1;
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

    bfs(0);
    for(int i=0;i<n;i++)
    {
        cout<<level[i]<<" ";
    }
    return 0;
}
