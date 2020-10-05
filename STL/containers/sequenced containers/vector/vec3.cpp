#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>vec;

    for(int i=0;i<5;i++)
        vec.push_back(i);

    cout<<vec[3]<<"\n";

    cout<<vec.at(3)<<"\n";  //it shows elemnt present on that particular index
    cout<<vec.front()<<"\n";//points to the first element
    cout<<vec.back()<<"\n";//points to the last element

    int *pos;   // points to first element of vector
    pos=vec.data();
    cout<<*pos<<"\n ";

    return 0;
}
