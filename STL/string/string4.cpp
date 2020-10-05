
#include"iostream"
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
    string s1("abcdefghijklmn");

    for(int i=0;i<s1.length();i++)
        cout<<s1.at(i)<<endl;

    cout<<s1.at(4);

    string s("adddwwbcdwdabdws e");
    int x;
    x=s.find("dd");
    cout<<x<<endl;

    int x1;
    x1=s.find_first_of("b");
    cout<<x1<<endl;

    int x2;
    x2=s.find_last_of("w");
    cout<<x2<<endl;

    string a1("abcdcgkhxsajhs");
    cout<<a1.substr(3 ,2);



    return 0;

}

