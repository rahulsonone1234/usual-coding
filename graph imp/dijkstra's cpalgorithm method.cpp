#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

vector<vector<pair<int, int>>>adj(1000);
vector<int>dist(100005);
vector<int>pre(100005);
vector<bool>visited(100005);


void dijkstra(int s, int n)
{   
    dist[s]=0;
    for(int i=0;i<n;i++)
    {
        int minvertex=-1;
        for(int j=0;j<n;j++)
        {
            if(!visited[j]&&(minvertex==-1||dist[j]<dist[minvertex]))
            {
                minvertex=j;
            }
        }
        if(dist[minvertex]==INF)
        break;
        
        visited[minvertex]=true;
        for(auto x:adj[minvertex])
        {
            int v=x.first;
            int wt=x.second;
            
            if(dist[v]>dist[minvertex]+wt)
            {
                dist[v]=dist[minvertex]+wt;
                pre[v]=minvertex;
                
            }
        }
    }
    
   for(int i=0;i<n;i++)
   {
       cout<<i<<" "<<dist[i];
       cout<<endl;
   }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x].push_back(make_pair(y, wt));
        adj[y].push_back(make_pair(x, wt));
    }
    dist.assign(n, INF);
    pre.assign(n, -1);
    visited.assign(n, false);
    
    dijkstra(0, n);
    return 0;
}
