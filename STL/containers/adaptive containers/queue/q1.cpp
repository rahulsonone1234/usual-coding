#include<bits\stdc++.h>
using namespace std;

int main()
{
    queue<int>q;

    for(int i=0;i<5;i++)
        q.push(i);

    cout<<q.front()<<"\n";
    cout<<q.back()<<"\n";
    cout<<q.size()<<"\n";

    if(q.empty())
        cout<<"\nQueue is empty\n";
    else
        cout<<"\nQueue is not empty\n";

  //  cout<<q.pop()<<"\n";


    return 0;
}
