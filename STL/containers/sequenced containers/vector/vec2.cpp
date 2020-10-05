#include<bits/stdc++.h>
using namespace std;
//for usinf r and cr use reverse iterator
int main()
{
    vector<int>vec;
    int i;
    for(i=0;i<5;i++)
        vec.push_back(i);

    cout<<vec.size()<<" is the size of vector\n";
    cout<<vec.capacity()<<" is the capacity of vector\n";
    cout<<vec.max_size()<<" is the maxsize of vector\n";
//resize(4);//but if greater than before one then that element would be added with any default value but if not given then it is 1 by default
    vec.resize(9 ,5);
    cout<<vec.size()<<" is the new size of vector\n";

    if(vec.empty())
        cout<<"Vector is empty\n";
    else
        cout<<"vector is not empty\n";

//    vec.reserve();

//    vec.shrink_to_fit();  after capacity all elements are destroyed if we have stored upto 5 then after 5 all will be destroyed
    vector<int>::iterator it;
    for(it=vec.begin();it!=vec.end();++it)
        cout<<*it<<" ";

    return 0;
}
