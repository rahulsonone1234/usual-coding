#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    queue<string>q;
    set<int>visit;
    
    string t="1";
    
    q.push(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        
        int rem=0;
        for(int i=0;i<t.length();i++)
        {
            rem=rem*10+(t[i]-'0');
            rem%=n;
        }
        
        if(rem==0)
        {
            cout<<t<<endl;
            return 0;
        }
        
        else if(visit.find(rem)==visit.end())
        {
            visit.insert(rem);
            q.push(t+"0");
            q.push(t+"1");
        }
    }
    return 0;
}
