#include<bits/stdc++.h>
#define NIL -1

using namespace std;

vector<vector<int>>adj(1000);

int disc[1000001]={NIL};
int low[1000001]={NIL};
bool stkmem[1000001]={false};
stack<int>*st;

void dfs(int s)
{
    static int time=0;
    disc[s]=low[s]=++time;
    st->push(s);
    stkmem[s]=true;
    
    
    for(auto it=adj[s].begin();it!=adj[s].end();it++)
    {
        if(disc[*it]==-1)
        {
            dfs(*it);
            low[s]=min(low[s], low[*it]);
        }
        else if(stkmem[*it]==true)
        {
            low[s]=min(low[s], disc[*it]);
        }
    }
    int w = 0;  
    if (low[s] == disc[s]) 
    { 
        while (st->top() != s) 
        { 
            w = (int) st->top(); 
            cout << w << " "; 
            stkmem[w] = false; 
            st->pop(); 
        } 
        w = (int) st->top(); 
        cout << w <<endl; 
        stkmem[w] = false; 
        st->pop(); 
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
    }
    for(int i=0;i<n;i++)
    {
        if(disc[i]==NIL)
        {
            dfs(i);
        }
    }
}
