//CPP code to illustrate operators in pair
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	tuple<string, int, int>t1;
	tuple<string, int, int>t2 ;
	t1=make_tuple("Rajesh",12,23);
	t2=make_tuple("Ramman",13,34);


	cout << (t1 == t2) << endl;
	cout << (t1 != t2) << endl;
	cout << (t1 >= t2) << endl;
	cout << (t1 <= t2) << endl;
	cout << (t1 > t2) << endl;
	cout << (t1 < t2) << endl;

	return 0;
}

//swaping cane done directly  p1.swap(p2);
