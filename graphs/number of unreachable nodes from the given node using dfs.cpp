#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
bool visited[1000001]={false};

int ans=0;
void dfs(int s)
{
    visited[s]=true;
    //cout<<s<<" ";
    ans++;
    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
        {
            dfs(adj[s][i]);
        }
    }
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
    int s;
    cin>>s;
    dfs(s);
    cout<<"Number of Unreachable nodes from the given node: "<<n-ans<<endl;
    return 0;
}
