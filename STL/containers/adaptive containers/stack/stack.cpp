#include<bits\stdc++.h>
using namespace std;

int main()
{
    stack<int>s1;

    for(int i=0;i<5;i++)
        s1.push(i);

    cout<<s1.size()<<"\n";
    if(s1.empty())
        cout<<"Stack is empty";
    else
        cout<<"Stack is not empty";

   // for(int i=0;i<5;i++)
        cout<<s1.top()<<" ";
    s1.pop();
//    s1.clear();



    return 0;
}
