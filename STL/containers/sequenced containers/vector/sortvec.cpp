#include<bits/stdc++.h>

using namespace std;
int main()
{
    vector<int>vec;

    for(int i=0;i<10;i++)
        vec.push_back(i);

    cout<<":Before sorting:";
    for(int i=0;i<vec.size();i++)
        cout<<vec.at(i);

    sort(vec.begin() ,vec.end(),greater<int>());

    cout<<":After sorting:";
    for(int i=0;i<vec.size();i++)
        cout<<vec.at(i);
//to copy the vector

    return 0;
}

