#include<bits/stdc++.h>
using namespace std;

int main()
{
   vector<int>v1,v2;

   v1.push_back(1);
   v1.push_back(2);
   for(int i=0;i<v1.size();i++)
        cout<<v1.at(i);
    cout<<"\n";

   v2.push_back(3);
   v2.push_back(4);
   for(int i=0;i<v2.size();i++)
        cout<<v2.at(i);
    cout<<"\n";

   v1.swap(v2);

   for(int i=0;i<v1.size();i++)
        cout<<v1.at(i);

   cout<<"\n";
   for(int i=0;i<v2.size();i++)
        cout<<v2.at(i);

   return 0;
}
