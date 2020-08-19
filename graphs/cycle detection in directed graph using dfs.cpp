#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
int visited[100001]={0};
int recstack[100001]={0};

int dfs(int s)
{
    if(visited[s]==0)
    {
        visited[s]=1;
        recstack[s]=1;
        for(auto it=adj[s].begin();it!=adj[s].end();it++)
        {
            if((!visited[*it]&&dfs(*it))|| recstack[*it])
            {
                return 1;
            }
        }
    }
    recstack[s]=0;
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
        if(visited[i]==0&&dfs(i))
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
