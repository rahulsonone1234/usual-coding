#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
bool visited[1000001]={false};
queue<int>q;
int level[1000001]={0};

int k=0;

void bfs(int s, int x)
{
    visited[s]=true;
    q.push(s);
    level[s]=1;
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
                
                if(level[*it]==x)
                {
                    k++;
                }
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
    int x;
    cin>>x;
    bfs(1, x);
    cout<<k<<endl;
    return 0;
}
