#include<bits/stdc++.h>
using namespace std;
map<string, bool>mp;
bool isScramble(string s1, string s2)
{
    if(s1.length()!=s2.length())
    return false;
    
    int n=s1.length();
    
    if(n==0) return true;
    
    if(s1==s2) return true;
    
    //Checking Anagram
    string s1_copy=s1;
    string s2_copy=s2;
    sort(s1_copy.begin(), s1_copy.end());
    sort(s2_copy.begin(), s2_copy.end());
    if(s1_copy!=s2_copy)return false;
    
    string key=s1;
    key.append(" ");
    key.append(s2);
    if(mp.find(key)!=mp.end())
    return mp[key];
    for(int i=1;i<n;i++){
        if(isScramble(s1.substr(0, i), s2.substr(0, i))&&isScramble(s1.substr(i, n-i), s2.substr(i, n-i)))
        {
            return true;
        }
        
        if(isScramble(s1.substr(0, i), s2.substr(n-i, i))&&isScramble(s1.substr(i, n-i), s2.substr(0, n-i)))
        {
            return true;
        }
        
    }
    mp[key]=false;
    return false;
}
int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    mp.clear();
    cout<<isScramble(s1, s2)<<endl;
    return 0;
}
