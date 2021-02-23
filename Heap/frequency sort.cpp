#include<bits/stdc++.h>
using namespace std;
bool sortbyval(const pair<int, int>&a, const pair<int, int>&b)
{
    if(a.second==b.second)
    return a.first<b.first;
    
    return a.second>b.second;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        unordered_map<int, int>mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
        }
        
       vector<pair<int, int>>v;
       
       copy(mp.begin(), mp.end(), back_inserter(v));
       sort(v.begin(), v.end(),sortbyval);
       
       for(int i=0;i<v.size();i++)
       {
           while(v[i].second--)
           {
               cout<<v[i].first<<" ";
           }
       }
        cout<<endl;
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        unordered_map<int, int>mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
        }
        
        priority_queue<pair<int, int>>pq;
        for(auto it:mp)
        {
            pq.push({it.second, it.first});
        }
        vector<int>ans;
        while(!pq.empty())
        {
            int freq=pq.top().first;
            int ele=pq.top().second;
            pq.pop();
            while(freq--)
            {
                cout<<ele<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
