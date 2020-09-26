#include<bits/stdc++.h>
using namespace std;
map<string, int>mp;
int solve(string s, int i, int j, bool istrue)
{
    if(i>j)
        return true;
    if(i==j)
    {
        if(istrue==true)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    string tmp=tostring(i);
    tmp.append(j);
    tmp.append(istrue);
    if(mp.find(tmp)!=mp.end())
    return mp[tmp];
    
    int ans=0;
    for(int k=i;k<=j-1;k=k+2)
    {
        int lt=solve(s, i, k-1, true);
        int lf=solve(s, i, k-1, false);
        int rt=solve(s, k+1, j, true);
        int rf=solve(s, k+1, j, false);
        if(s[k]=='&')
        {
            if(istrue==true)
            ans=ans+(lt*rt);
            else
            ans=ans+(lt*rt)+(lf*rt)+(lf*rf);
        }
        else if(s[k]=='|')
        {
            if(istrue==true)
            ans=ans+(lt*rf)+(lf*rt)+(rt*lt);
            else
            ans=ans+(lf*rt);
        }
        else if(s[k]=='^')
        {
            if(istrue==true)
            ans=ans+(lt*rf)+(rf*lt);
            else
            ans=ans+(lt*rt)+(rf*lf);
        }
    }
    return mp[tmp]=ans;
}
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    mp.clear();
    cout<<solve(s, 0, n,true)<<endl;
    return 0;
} 
