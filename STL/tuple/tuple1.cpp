#include<bits/stdc++.h>
#include<utility>
using namespace std;
int main()
{
    tuple<string ,int ,int>t1;
    t1=make_tuple("Ramesh",12 ,13);

    cout<<get< 0>(t1)<<"\n";//this will print ramesh

    return ;
}
