#include<bits/stdc++.h>
using namespace std;
int res[1001][1001];

int main()
{
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    memset(res,-1,sizeof(res));
    int n=s1.length();
    int m=s2.length();
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0||j==0)
            res[i][j]=0;
            else if(s1[i-1]==s2[j-1])
            res[i][j]=1+res[i-1][j-1];
            else
            res[i][j]=max(res[i-1][j], res[i][j-1]);
        }
    }
  //  cout<<"lcs length is: "<<res[n][m]<<endl;
    string ans;
    int i=n;
    int j=m;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(res[i-1][j]>res[i][j-1])
        {
            ans.push_back(s1[i-1]);
            i--;
        }
        else
        {
            ans.push_back(s2[j-1]);
            j--;
        }
    }
    while(i>0)
    {
        ans.push_back(s1[i-1]);
        i--;
    }
    while(j>0)
    {
        ans.push_back(s2[j-1]);
        j--;
    }
    reverse(ans.begin(), ans.end());
    cout<<"Common Subsequence :"<<ans<<endl;
    return 0;
}
