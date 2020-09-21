#include<bits/stdc++.h>
using namespace std;
int res[1001][1001];

int main()
{
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
   // memset(res,-1,sizeof(res));
    int n=s1.length();
    int m=s2.length();
    int ans=0;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0||j==0)
            res[i][j]=0;
            else if(s1[i-1]==s2[j-1]){
            res[i][j]=1+res[i-1][j-1];
                ans=max(ans, res[i][j]);
            }
            else
            res[i][j]=0;
        }
    }
    cout<<"lcs length is: "<<ans<<endl;
    return 0;
}
