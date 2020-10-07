// CPP program to find quotient and remainder 
// when a number is divided by large number 
// represented as string. 
#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

// Function to calculate the modulus 
void modBigNumber(string num, ll m) 
{ 
	// Store the modulus of big number 
	vector<int> vec; 
	ll mod = 0; 

	// Do step by step division 
	for (int i = 0; i < num.size(); i++) { 
		
		int digit = num[i] - '0'; 

		// Update modulo by concatenating 
		// current digit. 
		mod = mod * 10 + digit; 

		// Update quotient 
		int quo = mod / m; 
		vec.push_back(quo); 

		// Update mod for next iteration. 
		mod = mod % m;		 
	} 

	cout << "\nRemainder : " << mod << "\n"; 

	cout << "Quotient : "; 

	// Flag used to remove starting zeros 
	bool zeroflag = 0; 
	for (int i = 0; i < vec.size(); i++) { 
		if (vec[i] == 0 && zeroflag == 0) 
			continue; 
		zeroflag = 1; 
		cout << vec[i]; 
	} 

	return; 
} 

// Driver Code 
int main() 
{ 
	string num = "14598499948265358486"; 
	ll m = 487; 
	modBigNumber(num, m); 
	return 0; 
} 
