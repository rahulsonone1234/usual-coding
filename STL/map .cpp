#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string , int>mp;
    mp.clear();
    
    mp["abc"]=12;
    mp["xyz"]=13;
    
    mp.insert(make_pair("abcxyz",14));
    for(int i=0;i<2;i++)
    {
        string s1;
        cin>>s1;
        int a;
        cin>>a;
        mp.insert(make_pair(s1,a));
    }
    
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    
    string ss;
    cin>>ss;
    if(mp.find(ss)!=mp.end())
    cout<<mp[ss]<<endl;

    return 0;
}
