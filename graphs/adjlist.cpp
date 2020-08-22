#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>adj[n];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<n;i++)
    {
        cout<<i<<" :";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>>adj[1000];
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
        cout<<i<<" makes an edge with\n";
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {   
            cout<<it->first<<" having weight "<<it->second<<endl;
        }
        cout<<endl;
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>>adj(1000);
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
        cout<<i<<" makes an edge with\n";
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {   
            cout<<it->first<<" having weight "<<it->second<<endl;
        }
        cout<<endl;
    }
    return 0;
}
