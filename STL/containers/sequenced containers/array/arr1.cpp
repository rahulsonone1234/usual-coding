#include<bits/stdc++.h>
#include<array>
#include<tuple>
using namespace std;

int main()
{
    array<int ,6>arr;

    for(int i=0;i<arr.size();i++)
        cin>>i;

    cout<<"\n";
    for(int i=0;i<arr.size();i++)
        arr.at(i);

        cout<<"\n to access the element of the array we have 3 types {{{at(i)}}}  {{{{get(i)}}}  {{{{[]}}}}"<<;


        arr.front();cout<<"Return the value of first element";
        arr.back();cout<<"Returns the value of last element";
        arr.size();arr.max_size();cout<<"\nBoth the function call returns the size of the array";
        arr1.swap(arr2);cout<<"exchange all the elements of one array with other";
        arr.empty();cout<<"if the array is empty then it will return 1 else return 0";
        arr.fill(0);cout<<"fills all the element with the value passed as a argument";

        return 0;
}
