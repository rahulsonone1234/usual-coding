#include"iostream"
#include<vector>
#include<iterator>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>vec;
    int i;
    for(i=1;i<5;i++)
        vec.push_back(i);

    vector<int>::iterator it;
    for(it=vec.begin();it!=vec.end();++it)
        cout<<*it  ;

    cout<<"\n";
    vector<int>::iterator it1;
    for(it1=vec.cbegin();it1!=vec.cend();++it1)
        cout<<*it  ;

    cout<<"\n";
    vector<int>::iterator it2;
    for(it2=vec.rbegin();it2!=vec.rend();++it2)
        cout<<*it2  ;

    cout<<"\n";
    vector<int>::iterator it3;
    for(it3=vec.crbegin();it3!=vec.crend();++it3)
        cout<<*it3  ;

    return 0;
}
