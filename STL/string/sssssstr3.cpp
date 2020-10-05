#include"iostream"
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
  /* string s1("abcde");
   string s2("abcde");

   if(s1==s2)
    cout<<"equal"<<endl;
   else
    cout<<"notequal"<<endl;

   printf("%d",s1.compare(s2));*/
   string s1;
   cin>>s1;
   cout<<s1<<endl;

   cout<<"size of string is="<<s1.size()<<endl;
   cout<<"Length of string is="<<s1.length()<<endl;
   cout<<"capacity of string is="<<s1.capacity()<<endl;
   cout<<"max size of string is="<<s1.max_size()<<endl;
   cout<<"if string is empty="<<s1.empty()<<endl;


    return 0;

}

