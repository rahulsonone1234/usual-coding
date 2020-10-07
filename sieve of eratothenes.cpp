// C++ program to print all primes smaller than or equal to 
// n using Sieve of Eratosthenes 
#include <bits/stdc++.h> 
using namespace std; 

void SieveOfEratosthenes(int n) 
{ 
	// Create a boolean array "prime[0..n]" and initialize 
	// all entries it as true. A value in prime[i] will 
	// finally be false if i is Not a prime, else true. 
	bool prime[n+1]; 
	memset(prime, true, sizeof(prime)); 

	for (int i=2; i*i<=n; i++) 
	{ 
		// If prime[i] is not changed, then it is a prime 
		if (prime[i] == true) 
		{ 
			// Update all multiples of i greater than or 
			// equal to the square of it 
			// numbers which are multiple of i and are 
			// less than i^2 are already been marked. 
			for (int j=i*i; j<=n; j += i) 
			{
			    prime[j] = false;   
			}
		} 
	} 

	// Print all prime numbers 
	for (int i=2; i<=n; i++){
	    if (prime[i]){
	        cout << i << " ";   
	    }
	}
} 

// Driver Program to test above function 
int main() 
{ 
	int n = 50; 
	cout << "Following are the prime numbers smaller "
		<< " than or equal to " << n << endl; 
	SieveOfEratosthenes(n); 
	return 0; 
} 
