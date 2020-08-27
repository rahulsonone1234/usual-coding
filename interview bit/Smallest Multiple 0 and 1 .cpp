if(A==0)
        return "0";
 
    int val[A+1], par[A+1], flag[A+1];
    memset(val,-1,sizeof(val));
    memset(par,-1,sizeof(par));
    memset(flag,0,sizeof(flag));
 
    queue<int> q;
 
    q.push(1%A);
    par[1%A] = -1;
    val[1%A] = 1;
    flag[1%A] = 1;
 
    while(!q.empty())
    {
        int num = q.front();
        q.pop();
 
        if(num == 0)
        {
            string s = "";
 
            while(num!=-1)
            {
                s.push_back(val[num] + '0');
                num = par[num];
            }
 
            reverse(s.begin(), s.end());
 
            return s;
        }
 
        int num0 = (num*10)%A;
        int num1 = (num*10 + 1)%A;
 
        if(flag[num0]==0)
        {
            flag[num0] = 1;
            par[num0] = num;
            val[num0] = 0;
            q.push(num0);
        }
 
        if(flag[num1] == 0)
        {
            flag[num1] = 1;
            par[num1] = num;
            val[num1] = 1;
            q.push(num1);
        }
 
    }
///////////////////////////////////////////////////////////////////////////////////////////
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
