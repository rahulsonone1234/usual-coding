#include<bits\stdc++.h>

using namespace std;

int main()//multimap allows duplicate keys toe teas
{
    multimap<string ,int>bro;
    bro.insert(pair<string ,int>("shubham",20));
    bro.insert(pair<string ,int>("mangesh",21));
    bro.insert(pair<string ,int>("shivanand",22));
    bro.insert(make_pair("nikhilya",24));
    bro.insert(make_pair("mangesh",24));//duplication is allowed in multimap
   // bro["mangesh"]=21;is valid only in map but not in multimap
    //bro["shivanand"]=22;

    multimap<string ,int>::iterator it;
      //  auto it; shortcut but can't be use in most of the compilers


    for(it=bro.begin();it!=bro.end();it++)
        cout<<it->first<<":"<<it->second<<endl;

    cout<<"Size of the map is "<<bro.size()<<"\n";
    if(bro.empty())
        cout<<"\n multimap is empty\n";
    else
        cout<<"\n multimap is not empty\n";

    //upper bound and lower bound is for just to have a selection for a particulr range

    multimap<string ,int>::iterator lb=bro.lower_bound("mangesh");
    multimap<string ,int>::iterator ub=bro.upper_bound("nikhilya");

    for(it=lb;it!=ub;it++)
        cout<<it->first<<":"<<it->second<<endl;

    return 0;
}
