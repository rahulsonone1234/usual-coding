#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
int visited[100001]={0};

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
    stack<int>s;
    
    int src;
    cin>>src;
    s.push(src);
    
    while(!s.empty())
    {
        int s1=s.top();
        s.pop();
        
        if(visited[s1]==0)
        {
            cout<<s1<<" ";
            visited[s1]=1;
        }
        vector<int>::iterator it;
        for(it=adj[s1].begin();it!=adj[s1].end();it++)
        {
            if(!visited[*it])
            {
                s.push(*it);
            }
        }
        
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
int visited[100001]={0};

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
    stack<int>s;
    
    int src;
    cin>>src;
    cout<<src<<" ";
    s.push(src);
    visited[src]=1;
    while(!s.empty())
    {
        int s1=s.top();
        s.pop();
        vector<int>::iterator it;
        for(it=adj[s1].begin();it!=adj[s1].end();it++)
        {
            if(visited[*it]==0)
            {
                s.push(s1);
                visited[*it]=1;
                cout<<*it<<" ";
                s.push(*it);
            }
        }
       
        
    }
    return 0;
}
