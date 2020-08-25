#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(1000);
vector<vector<int>>adjt(1000);
int visited[100005]={0};
stack<int>stk;
int ocount=0;
int ecount=0;

int trandfs(int s)
{
    visited[s]=true;
    cout<<s<<" ";
    int count=1;
    for(auto it:adjt[s])
    {
        if(!visited[it])
        {
            count+=trandfs(it);
        }
    }
    return count;
}

void filldfs(int s)
{
    visited[s]=true;
    for(auto it:adj[s])
    {
        if(!visited[it])
        {
            filldfs(it);
        }
    }
    stk.push(s);
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
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            filldfs(i);
        }
    }
    for(int i=0;i<100005;i++)
    {
        visited[i]=0;
    }
    int cnt=0;
    while(!stk.empty())
    {
        int v=stk.top();
        stk.pop();
        if(!visited[v])
        {
            cnt++;
            int count=trandfs(v);
            if(count%2)
            {
                ocount+=count;
            }
            else
            {
                ecount+=count;
            }
            cout<<endl;
        }
    }
    cout<<"Connected Components : "<<cnt<<endl;
    cout<<"Oddcount : "<<ocount<<endl;
    cout<<"Evencount : "<<ecount<<endl;
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

int even=0;
int odd=0;

void dfs(stack<int>& stk, int i, vector<bool>& visited, vector<vector<int> >& adjList)
{
    visited[i] = true;
    for (auto& ele: adjList[i])
    {
        if (!visited[ele])
        {
            dfs(stk, ele, visited, adjList);
        }
    }
    stk.push(i);
}

int print(vector<bool>& visited, int temp, vector<vector<int> >& adjListRev)
{
    visited[temp] = true;
    int count=1;
    for (auto& ele: adjListRev[temp])
    {
        if (!visited[ele])
        {
            count += print(visited, ele, adjListRev);
        }
    }
    return count;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adjList(n), adjListRev(n);
    for (int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
        adjListRev[b].push_back(a);
    }

    stack<int> stk;
    vector<bool> visited(n, false);
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
        dfs(stk, i, visited, adjList);
    }

    for (int i=0;i<n;i++)
    visited[i] = false;

    while (!stk.empty())
    {
        int temp = stk.top(); stk.pop();
        if (!visited[temp])
        {
            int count = print(visited, temp, adjListRev);
            if (count&1) odd += count;
            else even += count;
        }
    }

    cout << (odd-even) << endl;
    return 0;
}

