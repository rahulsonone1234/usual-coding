#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);

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
    
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            indegree[*it]++;
        }
    }
    
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    int cnt=0;
    
    
    vector<int>output;
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        output.push_back(u);
        
        for(auto it=adj[u].begin();it!=adj[u].end();it++)
        {
            if(--indegree[*it]==0)
            {
                q.push(*it);
            }
        }
        cnt++;
    }
    
    if(cnt!=n)
    {
        cout<<"Cycle exist"<<endl;
        return 0;
    }
    
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return 0;
    
}
