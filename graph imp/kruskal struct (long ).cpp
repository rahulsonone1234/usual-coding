#include<bits/stdc++.h>
using namespace std;

class Edge
{
	public :
		int src;
		int dest;
		int wt;
};

bool compare(Edge e1,Edge e2)
{
	return e1.wt<e2.wt;
}
int findparent(int v,int *parent)
{
	if(parent[v]==v)
	return v;
	else
	{
		findparent(parent[v],parent);
	}
	
}
void kruskals(Edge *input,int n ,int E)
{
	sort(input ,input+E ,compare);
	Edge *output=new Edge[n-1];

	int *parent=new int[n];
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}


	int cnt=0;
	int i=0;
	while(cnt!=n-1)
	{
		Edge curredge=input[i];
		int srcparent=findparent(curredge.src ,parent);
		int destparent=findparent(curredge.dest ,parent);
		if(srcparent!=destparent)
		{
			output[cnt]=curredge;
			cnt++;
			parent[srcparent]=destparent;
		}
		i++;	
	}
	for(int i=0;i<n-1;i++)
	{
		if(output[i].src<output[i].dest)
		{
			cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].wt;
		}		
		else
		{
			cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].wt;
		}
		
	}
}
int main()
{
	int n,E;
	cin>>n>>E;
	Edge *input=new Edge[E];
	
	for(int i=0;i<E;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		input[i].src=s;
		input[i].dest=d;
		input[i].wt=w;
	}
	kruskals(input, n ,E);
	return 0;
}
