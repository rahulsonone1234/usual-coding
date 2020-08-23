#include<bits/stdc++.h>
using namespace std;

vector<pair<int ,int>>adj(1000);
vector<int>parent;

int find(int v)
{
    if(parent[v]==-1)
    {
        return v;
    }
    return find(parent[v]);
}

void unionf(int u1, int v1)
{
    int u=find(u1);
    int v=find(v1);
    
    parent[u]=v;
}

bool isCyclic()
{
    for(auto x:adj)
    {
        int u=find(x.first);
        int v=find(x.second);
        
        if(u==v)
        {
            return true;
        }
        
        unionf(u, v);
    }
    return false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj.push_back(make_pair(x, y));
    }
    parent.resize(n, -1);
    
    if(isCyclic())
    {
        cout<<"cycle is present "<<endl;
    }
    else
    {
        cout<<" no cycle is present "<<endl;
    }
    return 0;
}
