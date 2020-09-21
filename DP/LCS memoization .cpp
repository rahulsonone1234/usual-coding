#include<bits/stdc++.h>
using namespace std;
int res[1001][1001];
int lcs(string s1, string s2,int n,int m)
{
    if(res[n][m]!=-1)
    return res[n][m];
    
    if(s1[n-1]==s2[m-1])
    return res[n][m]=1+lcs(s1,s2,n-1,m-1);
    else
    return res[n][m]=max(lcs(s1,s2,n-1,m), lcs(s1,s2,n,m-1));
}
int main()
{
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    memset(res,-1,sizeof(res));
    cout<<"Length of lcs "<<lcs(s1,s2,s1.length(),s2.length())<<endl;
    return 0;
}
