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

