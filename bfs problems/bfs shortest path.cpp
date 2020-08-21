#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
bool visited[100005]={false};

deque<int>q;

int dist[100005]={0};
int pre[100005]={0};

bool bfs(int s, int d)
{
    visited[s]=true;
    dist[s]=0;
    q.push_back(s);
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop_front();
        for(auto it=adj[u].begin();it!=adj[u].end();it++)
        {
            if(visited[*it]==false)
            {
                visited[*it]=true;
                dist[*it]=dist[u]+1;
                pre[*it]=u;
                q.push_back(*it);
                
                
                if(*it==d)
                {
                    return true;
                }
            }
        }
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
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        dist[i]=INT_MAX;
        pre[i]=-1;
    }
    int s,d;cin>>s>>d;
    bfs(s, d);
    cout<<"distance is :"<<dist[d]<<endl;
    
    vector<int>p;
    int cr=d;
    p.push_back(cr);
    while(pre[cr]!=-1)
    {
        p.push_back(pre[cr]);
        cr=pre[cr];
    }
    cout<<"Path is :";
    for(int i=p.size()-1;i>=0;i--)
    {
        cout<<p[i]<<" ";
    }
    return 0;
}
