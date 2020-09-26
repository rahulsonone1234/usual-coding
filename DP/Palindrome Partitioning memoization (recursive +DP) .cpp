#include<bits/stdc++.h>
using namespace std;
int res[1001][1001];
bool isplaindrome(string s, int i, int j)
{
    if(i==j)
    return true;
    
    if(i>j)
    return true;
    
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
            
        i++;
        j--;
    }
    return true;
    
}
int palindromePartitioning(string s, int i, int j)
{
    if(i>=j)
    return 0;
    
    if(isplaindrome(s, i, j)==true)
    return 0;
    
    if(res[i][j]!=-1)
    return res[i][j];
    
    int min=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int tmp=(palindromePartitioning(s,i,k)+palindromePartitioning(s,k+1,j))+1;
        if(tmp<min)
        {
            min=tmp;
        }
    }
    return res[i][j]=min;
}
    

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    memset(res, -1, sizeof(res));
    cout<<palindromePartitioning(s, 1, n)<<endl;
    return 0;
}pla
