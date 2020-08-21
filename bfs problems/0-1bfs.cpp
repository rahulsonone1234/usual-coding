#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>>adj[1000];
int disc[100005]={0};
deque<int>dq;

void bfs(int s)
{
      dq.push_back(s);
      disc[s]=0;
      while(!dq.empty())
      {
          int u=dq.front();
          dq.pop_front();
          
          for(auto it:adj[u])
          {
            if(disc[it.first]>disc[u]+it.second)
            {
                disc[it.first]=disc[u]+it.second;
                if(it.second==1)
                {
                    dq.push_back(it.first);    
                }
                else
                {
                    dq.push_front(it.first);   
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
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x].push_back(make_pair(y, wt));
        adj[y].push_back(make_pair(x, wt));
    }
    for(int i=0;i<n;i++)
    {
        disc[i]=INT_MAX;
    }
    bfs(0);
    
    for(int i=0;i<n;i++)
    {
        cout<<disc[i]<<" ";
    }
    return 0;
}
