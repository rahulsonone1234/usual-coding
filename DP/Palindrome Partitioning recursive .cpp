#include<bits/stdc++.h>
using namespace std;
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
    
    int min=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int tmp=(palindromePartitioning(s,i,k)+palindromePartitioning(s,k+1,j))+1;
        if(tmp<min)
        {
            min=tmp;
        }
    }
    return min;
}
    

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    cout<<palindromePartitioning(s, 1, n)<<endl;
    return 0;
}
