//CPP code to illustrate operators in pair
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	pair<int, int>pair1 = make_pair(1, 12);
	pair<int, int>pair2 = make_pair(9, 12);


	cout << (pair1 == pair2) << endl;
	cout << (pair1 != pair2) << endl;
	cout << (pair1 >= pair2) << endl;
	cout << (pair1 <= pair2) << endl;
	cout << (pair1 > pair2) << endl;
	cout << (pair1 < pair2) << endl;

	return 0;
}

//swaping cane done directly  p1.swap(p2);
