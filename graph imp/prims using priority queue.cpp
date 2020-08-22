#include<bits/stdc++.h>
#define INF 100000005
using namespace std;

vector<vector<pair<int, int>>>adj(1000);


void prims(int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    int src=0;
    vector<int>dist(n, INF);
    vector<int>parent(n, -1);
    vector<bool>inmst(n, false);
    
    
    pq.push(make_pair(0, src));
    dist[src]=0;
    
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        inmst[u]=true;
    
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 
            if (inmst[v] == false && dist[v] > weight) 
            { 
                dist[v] = weight; 
                pq.push(make_pair(dist[v], v)); 
                parent[v] = u; 
            } 
        } 
    }
    for (int i = 1; i < n; ++i) 
        printf("%d - %d :%d\n", parent[i], i, dist[i]); 
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
    prims(n);
    return 0;
}
