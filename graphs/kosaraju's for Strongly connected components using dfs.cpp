#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
vector<vector<int>>adjt(1000);
int visited[1000001]={0};
stack<int>st;

void transdfs(int s)
{
    visited[s]=1;
    cout<<s<<" ";
    for(auto it=adjt[s].begin();it!=adjt[s].end();it++)
    {
        if(!visited[*it])
        {
            transdfs(*it);
        }
    }
}
void filldfs(int s)
{
    visited[s]=1;
    for(auto it=adj[s].begin();it!=adj[s].end();it++)
    {
        if(!visited[*it])
        {
            filldfs(*it);   
        }
    }
    st.push(s);
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
        adjt[y].push_back(x);
    }
    //first dfs on original graph
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            filldfs(i);
        }
    }
    
    
    
    for(int i=0;i<1000001;i++)
    {
        visited[i]=0;
    }
    
    //dfs on transpose graph
    int cnt=0;
    while(st.empty()==false)
    {
        int v=st.top();
        st.pop();
        
        if(visited[v]==0)
        {
            transdfs(v);
            cout<<endl;
            cnt++;
        }
    }
    cout<<"SCC's in graph"<<cnt<<endl;
    return 0;
}
