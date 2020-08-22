#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

vector<vector<pair<int, int>>>adj(1000);

void dijkstra(int v, int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    vector<int>dist(v, INF);
    
    pq.push(make_pair(0, s));
    dist[s]=0;
    
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        
        for(auto x:adj[u])
        {
            int v=x.first;
            int wt=x.second;
            
            if(dist[v]>dist[u]+wt)
            {
                dist[v]=dist[u]+wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<" "<<dist[i]<<" ";
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
    
    dijkstra(n, 0);
    return 0;
}
