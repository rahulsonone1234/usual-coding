#include<bits/stdc++.h>

using namespace std;
int main()
{
    vector<int>vec;

    int i;
    //for(i=0;i<5;i++)
      //  vec.push_back(i);
    for(i=0;i<10;i++)
    {
        //vec.assign(10 ,i);
       // cout<<vec[i]<<" ";
       vec.push_back(i);
    }

    vec.insert(vec.begin(),99);
    vec.erase(vec.begin());
//    vec.emplace(vec.begin(),8);
//    vec.emplace_back(67);
vec.clear();

    for(i=0;i<vec.size();i++)
       cout<<vec[i]<<" ";

    return 0;

}
