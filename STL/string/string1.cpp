#include"iostream"
#include<string>
using namespace std;

int main()
{
   /* string s1("abcdef");
    string s2("123");
    s2.insert(2,s1);
    cout<<s2<<endl;

    s2.erase(1,6);
    cout<<s2;*/

    string a("abcede");
    string b("123456");

    b.replace(1 ,4 ,a);
    cout<<b;



    return 0;

}

