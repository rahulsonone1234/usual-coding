#include"iostream"
#include<string>
using namespace std;

int main()
{
    string s1;
   //string s1("Rsbmssm");
    cin>>s1;
    getline(cin ,s1);
    cout<<s1;

    s1="agh";
    cout<<s1;


    string s2;
    s2=s1;//string s2(s1);
    cout<<s2;

    string a("awd");
    string b("aws");
    string c=a+b;
    cout<<c;


    return 0;

}

