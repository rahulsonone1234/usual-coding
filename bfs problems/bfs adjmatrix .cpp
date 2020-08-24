#include<bits/stdc++.h>
using namespace std;

int G[10][10];
int visited[100005]={0};
int n;
queue<int>q;

void bfs(int s)
{
    visited[s]=1;
    q.push(s);
    int n=visited.size();
    while(!q.empty())
    {
        int u=q.front();
        cout<<u<<" ";
        q.pop(); 
        for(int i=0;i<n;i++)
        {
            if(G[s][i]==1&&(!visited[i]))
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
    
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>G[i][j];
        }
    }
    
    dfs(0);
    return 0;
}


/////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
vector<bool>visited;
queue<int>q;

void bfs(int s, int **edges)
{
    visited[s]=true;
    q.push(s);
    int n=visited.size();
    while(!q.empty())
    {
        int u=q.front();
        cout<<u<<" ";
        q.pop(); 
        for(int i=0;i<n;i++)
        {
            if(edges[s][i]==1&&(!visited[i]))
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
    
}
int main()
{
	int n, e;
	cin>>n>>e;
	int **edges=new int *[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j]=0;
		}
	}
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	visited.assign(n, false);
	bfs(0, edges);
	for(int i=0;i<n;i++)
	{
		delete[] edges[i];
	}
	delete []edges;

return 0;

}
