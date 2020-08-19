#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
int visited[100001]={0};
int color[100001]={0};

int dfs(int s)
{
    color[s]=1;
    for(auto it=adj[s].begin();it!=adj[s].end();it++)
    {
       if(color[*it]==1)
       return 1;
       
       if(color[*it]==0&&dfs(*it))
       return 1;
    }
    color[s]=2;
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
    }
    for(int i=0;i<n;i++)
    {
        if(color[i]==0)
        {
            if(dfs(i)==1)
            {
                cout<<"YES"<<endl;
                return 0;   
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
