#include<bits/stdc++.h>
using namespace std;
//data is always sorted in set
//set contains only unique values
int main()
{
    set<int>s;

    for(int i=0;i<10;i++)
        s.insert(10-i);

    s.insert(20);
    s.insert(30);
    s.insert(20);

    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++)
        cout<<*it<<"\n";

    return 0;
}
