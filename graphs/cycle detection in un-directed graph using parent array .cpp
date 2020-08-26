#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
int visited[100001]={0};


int dfs(int s, int parent)
{
    visited[s]=1;
    for(auto it=adj[s].begin();it!=adj[s].end();it++)
    {
       if(!visited[*it])
       {
           if(dfs(*it, s))
           {
               return 1;
           }
       }
       else if(*it !=parent)
       {
             return 1;   
       }
    }
    return 0;
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
        if(!visited[i])
        {
            if(dfs(i, -1))
            {
                cout<<"YES"<<endl;
                return 0;   
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
int visited[100001]={0};


int dfs(int s, int parent)
{
    visited[s]=1;
    for(auto it:adj[s])
    {
       if((!visited[it])&&dfs(it, s))
       {
               return 1;
       }
       else if(it!=parent)
       {
             return 1;   
       }
    }
    return 0;
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
        if(!visited[i])
        {
            if(dfs(i, -1))
            {
                cout<<"YES"<<endl;
                return 0;   
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}

