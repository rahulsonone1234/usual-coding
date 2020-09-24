#include<bits/stdc++.h>
using namespace std;
int res[1001][1001];

int main()
{
    string s1;
    string s2;
    cin>>s1;
    s2=s1;
    reverse(s2.begin(), s2.end());
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
    cout<<"Number of Insertions or Deletions that are required to make palindromic string "<<n-res[n][m]<<endl;
    return 0;
}
