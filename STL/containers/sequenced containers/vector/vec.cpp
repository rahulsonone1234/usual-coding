#include<stdio.h>
#include<stdlib.h>
#include"iostream"
#include<array>

using namespace std;

int main()
{
    array<int ,4>vec;

    for(int i=0;i<3;i++)
        vec.push_back(i);

    vec.pop_back();

   cout<<vec.size();
    return 0;
}
