#include<bits\stdc++.h>

using namespace std;
int main()
{
    list<int>li;

    for(int i=0;i<5;i++)
        li.push_back(i);

    li.push_front(10);

    list<int>::iterator it;

    for(it=li.begin();it!=li.end();it++)
        cout<<*it<<" ";
    return 0;


}
