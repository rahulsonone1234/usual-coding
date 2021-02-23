#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int k;
	    cin>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	   // for(int i=0;i<n;i++)
	   // {
	   //     cout<<a[i];
	   // }
	    
	    priority_queue<int, vector<int>, greater<int>>pq;
	    
	    for(int i=0;i<n;i++)
	    {
	        pq.push(a[i]);
	        if(pq.size()>=k)
	        {
	            cout<<pq.top()<<" ";
	            pq.pop();
	        }
	    }
	    while(!pq.empty())
	    {
	        cout<<pq.top()<<" ";
	        pq.pop();
	    }
	    
	    cout<<endl;
	}
	return 0;
}
