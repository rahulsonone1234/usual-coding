#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<string ,int>coffee_shop;

    coffee_shop["cappaccino"]=20;
    coffee_shop["softeee"]=10;
    coffee_shop["hardeeee"]=30;

  // Alternative  map<string ,int>coffee_shop{{"cappaccino",20},{"softeee",10},{"hardeee",30}}

  cout<<coffee_shop["cappaccino"]<<endl;
  if(coffee_shop.find("cappaccino")!=coffee_shop.end())
        cout<<"Key found\n";
  else
        cout<<"Not found";

  map<string ,int>::iterator it;

/*  for(it=coffee_shop.begin();it!=coffee_shop.end();it++)
  {
      cout<<it->first<<":"<<it->second<<"\n";
  }*/

  coffee_shop.insert(make_pair("cold_coffee",23));
  coffee_shop.insert(pair<string ,int>("cold_coffee",24));//it overwrites the previous value

  //coffee_shop.erase(it); erasing using iterator
  coffee_shop.erase("cold_coffee");
  for(it=coffee_shop.begin();it!=coffee_shop.end();it++)
  {
      cout<<it->first<<":"<<it->second<<"\n";
  }

    return 0;
}

