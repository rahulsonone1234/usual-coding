Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1

Explanation:
Testcase 1: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.

using namespace std;
// int max(int a, int b)
// {
//     return (a>b)?a:b;
// }
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int ls=a[0];
        int gs=a[0];
        for(int i=1;i<n;i++)
        {
            ls=max(a[i] ,ls+a[i]);
            gs=max(ls ,gs);
        }
        cout<<gs<<endl;
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////
Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

Output: 
For each testcase, print the sorted array.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

Explanation:
Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    int cnt1=0;
	    int cnt2=0;
	    int cnt3=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	       
	    }
	    for(int i=0;i<n;i++)
	    {
	         if(a[i]==0)
	        cnt1++;
	        if(a[i]==1)
	        cnt2++;
	        if(a[i]==2)
	        cnt3++;
	    }
	   
	    while(cnt1--)
	    {
	        cout<<0<<" ";
	    }while(cnt2--)
	    {
	        cout<<1<<" ";
	    }while(cnt3--)
	    {
	        cout<<2<<" ";
	    }
	    
	    cout<<endl;
	}
	return 0;
}

////////////////////////////////////////////////////////////////
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Input: 
First line contains number of test cases T. First line of each test case contains an integer value N denoting the number of days, followed by an array of stock prices of N days. 

Output:
For each testcase, output all the days with profit in a single line. And if there is no profit then print "No Profit".

Constraints:
1 <= T <= 100
2 <= N <= 103
0 <= Ai <= 104

Example
Input:
3
7
100 180 260 310 40 535 695
4
100 50 30 20
10
23 13 25 29 33 19 34 45 65 67

Output:
(0 3) (4 6)
No Profit
(1 4) (5 9)

Explanation:
Testcase 1: We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit.

#include<iostream>
using namespace std;
void get(int arr[],int n)
{
    int i=0,a=0,b=0;
    while(i<n-1)
    {
        while(i<n-1 && arr[i+1]<=arr[i])
        i++;
        if(i==n-1)
        break;
        a=i++;
        while(i<n && arr[i]>=arr[i-1])
        i++;
        b=i-1;
        cout<<"("<<a<<" "<<b<<")"<<" ";
    }
    if(a==0 && b==0)
    cout<<"No Profit";
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n; int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        get(arr,n);
        cout<<"\n";
    }
    return 0;
}
//////////////////////////////////////////////////////////
Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size n and m. The task is to merge the two sorted arrays into one sorted array (in non-decreasing order).

Note: Expected time complexity is O((n+m) log(n+m)). DO NOT use extra space.  We need to modify existing arrays as following.

Input: arr1[] = {10};
       arr2[] = {2, 3};
Output: arr1[] = {2}
        arr2[] = {3, 10}  

Input: arr1[] = {1, 5, 9, 10, 15, 20};
       arr2[] = {2, 3, 8, 13};
Output: arr1[] = {1, 2, 3, 5, 8, 9}
        arr2[] = {10, 13, 15, 20} 
Input:
First line contains an integer T, denoting the number of test cases. First line of each test case contains two space separated integers X and Y, denoting the size of the two sorted arrays. Second line of each test case contains X space separated integers, denoting the first sorted array P. Third line of each test case contains Y space separated integers, denoting the second array Q.

Output:
For each test case, print (X + Y) space separated integer representing the merged array.

Input:
2
4 5
1 3 5 7
0 2 6 8 9
2 3
10 12
5 18 20

Output:
0 1 2 3 5 6 7 8 9
5 10 12 18 20

Explanation:
Testcase 1: After merging two non-decreasing arrays, we have, 0 1 2 3 5 6 7 8 9.

 // extra space 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find next gap. 
int nextGap(int gap) 
{ 
	if (gap <= 1) 
		return 0; 
	return (gap / 2) + (gap % 2); 
} 

void merge(int *arr1, int *arr2, int n, int m) 
{ 
	int i, j, gap = n + m; 
	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
	{ 
		// comparing elements in the first array. 
		for (i = 0; i + gap < n; i++) 
			if (arr1[i] > arr1[i + gap]) 
				swap(arr1[i], arr1[i + gap]); 

		//comparing elements in both arrays. 
		for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++) 
			if (arr1[i] > arr2[j]) 
				swap(arr1[i], arr2[j]); 

		if (j < m) 
		{ 
			//comparing elements in the second array. 
			for (j = 0; j + gap < m; j++) 
				if (arr2[j] > arr2[j + gap]) 
					swap(arr2[j], arr2[j + gap]); 
		} 
	} 
} 

// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a1[n],a2[m];
        for(int i=0;i<n;i++)cin>>a1[i];
        for(int i=0;i<m;i++)cin>>a2[i];
        merge(a1, a2, n, m);

	for (int i = 0; i < n; i++) 
		printf("%d ", a1[i]); 

	for (int i = 0; i < m; i++) 
		printf("%d ", a2[i]); 
	printf("\n"); 
    }

	return 0; 
} 
//////////////////////////////////////////////////
Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.

Input:
The first line of input contains an integer T denoting the number of test cases. For each test case first line contains N(size of array). The subsequent line contains N-1 array elements.

Output:
Print the missing number in array.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ C[i] ≤ 107

Example:
Input:
2
5
1 2 3 5
10
1 2 3 4 5 6 7 8 10

Output:
4
9

Explanation:
Testcase 1: Given array : 1 2 3 5. Missing element is 4.

using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n-1;i++)
	    {
	        cin>>a[i];
	    }
	   int sum=0;
	   for(int i=0;i<n-1;i++)
	   {
	       sum=sum+a[i];
	   }
	   int tmp=(n*(n+1))/2;
	   cout<<tmp-sum<<endl;
	  
	}
	return 0;
}
///////////////////////////////////////////////////////////
min platforms
Input:
2
6 
0900  0940 0950  1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240 

Output:
3
1

Explanation:
Testcase 1: Minimum 3 platforms are required to safely arrive and depart all trains.
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int d[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<n;i++)
        cin>>d[i];
        
        sort(a ,a+n);
        sort(d ,d+n);
        int i=1;
        int j=0;
        int tmp=1;
        int res=1;
        while(i<n && j<n)
        {
            if(a[i]<=d[j])
            {
                tmp++;
                i++;
            }
            else if(a[i]>d[j])
            {
                tmp--;
                j++;
            }
            if(tmp>res)
            res=tmp;
        }
        cout<<res<<endl;
    }
    return 0;
}
//////////////////////////////////////


kth smallest
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int h[100005]={0};
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            h[a[i]]++;
        }
        int k;
        cin>>k;
        for(int i=0;i<100005;i++)
        {
            if(h[i]>=1)
            k--;
            
            if(k==0)
            {
                cout<<i<<endl;
                break;
            }
            
        }
        // sort(a,a+n);
        // int k;
        // cin>>k;
        // cout<<a[k-1]<<endl;
    }
    return 0;
}
////////////////////////////////////////
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

Input:  
The first line of the input contains T denoting the number of testcases. The first line of the test case will be the size of array and second line will be the elements of the array.

Output: 
For each test case the output will be the majority element of the array. Output "-1" if no majority element is there in the array.

Constraints:
1 <= T<= 100
1 <= N <= 107
0 <= Ai <= 106

Example:
Input:
2
5
3 1 3 3 2
3
1 2 3

Output:
3
-1

Explanation:
Testcase 1: Since, 3 is present more than N/2 times, so it is the majority element.
 



int majorityElement(int *array,int n)
{
//   unordered_map<int,int> map;

    int map[1000001] = {0};
   
   for (int i = 0; i < n; i++) {
       map[array[i]]++;
       
       if(map[array[i]]> n/2)
       return array[i];
   }
   
   return -1;
    
}

int main() {

    int t;
    cin >> t;
    
    while(t--)
    {
       int n,*array;
       cin >> n;
       array = new int[n];
       for (int i = 0; i < n; i++) {
           cin >> array[i];
       }
       
       cout << majorityElement(array,n)<<endl;
    }
    
	return 0;
}
/////////////////////////////////////
Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is r and c, r is the number of rows and c is the number of columns.
The second line of each test case contains all the elements of the matrix in a single line separated by a single space.

Output:
Print the modified array.

Constraints:
1 ≤ T ≤ 100
1 ≤ r, c ≤ 1000
0 ≤ A[i][j] ≤ 1

Example:
Input:
3
2 2
1 0
0 0
2 3
0 0 0 
0 0 1
4 3
1 0 0
1 0 0
1 0 0
0 0 0

Output:
1 1
1 0
0 0 1 
1 1 1
1 1 1
1 1 1
1 0 0

Explanation:
Testcase1: Since only first element of matrix has 1 (at index 1,1) as value, so first row and first column are modified to 1.
 
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        int r[n]={0},c[m]={0};
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    r[i]=1;c[j]=1;
                    
                }
            }
        }
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(r[i]==1||c[j]==1)
                {
                    a[i][j]=1;
                }
            }
        }
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
//////////////////////////////////////////
Input:
3
6
16 17 4 3 5 2
5
1 2 3 4 0
5
7 4 5 7 3
Output:
17 5 2
4 0
7 7 3

Explanation:
Testcase 3: All elements on the right of 7 (at index 0) are smaller than or equal to 7. Also, all the elements of right side of 7 (at index 3) are smaller than 7. And, the last element 3 is itself a leader since no elements are on its right.

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int max=INT_MIN;
        int j=0;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>=max)
            {
                max=a[i];
                b[j++]=max;
            }
        }
        for(int i=--j;j>=0;j--)
        cout<<b[j]<<" ";
        cout<<endl;
    }
}
//////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

int bin_search(int A[],int left,int right,int k);

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
            cin>>a[i];
        int key;
        cin>>key;
        int found = bin_search(a,0,N-1,key);
        cout<<found<<endl;
    }
}
// } Driver Code Ends


/*You need to complete this function */
int bin_search(int A[], int left, int right, int k)
{
    if(left<=right)
    {
        int mid=(left+right)/2;
        if(A[mid]==k)return mid;
        else if(A[mid]>k)
        return bin_search(A, left, mid-1 ,k);
        else if(A[mid]<k)
        return bin_search(A, mid+1, right, k);
        
    }return -1;
}
////////////////////////////////////////////////////////////////////
equilibrium point
Input:
2
1
1
5
1 3 5 2 2

Output:
1
3

Explanation:
Testcase 1: Since its the only element hence its the only equilibrium point.
Testcase 2: For second test case equilibrium point is at position 3 as elements below it (1+3) = elements after it (2+2).
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int sum=0;
        int lsum=0;
        for(int i=0;i<n;i++)
        sum+=a[i];
        int i;
        for( i=0;i<n;i++)
        {
            sum-=a[i];
            if(lsum==sum)
            {
                cout<<i+1<<endl;
                break;
            }
            lsum+=a[i];
        }
        if(i==n)
        cout<<-1<<endl;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////
2
6
1 2 3 4 5 6
11 
10 20 30 40 50 60 70 80 90 100 110

Output:
6 1 5 2 4 3
110 10 100 20 90 30 80 40 70 50 60

Explanation:
Testcase 1: Max element = 6, min = 1, second max = 5, second min = 2, and so on... Modified array is : 6 1 5 2 4 3.
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int a[n];
        for(long long int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        long long int maxid=n-1;
        long long int minid=0;
        long long int maxele=a[n-1]+1;
        for(long long int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                a[i]+=(a[maxid]%maxele)*maxele;
                maxid--;
            }
            else
            {
                a[i]+=(a[minid]%maxele)*maxele;
                minid++;
            }
        }
        for(long long int i=0;i<n;i++)
        {
            cout<<a[i]/maxele<<" ";
        }
        cout<<endl;
    }
}
//////////////////////////////////////////////////////////////////////////


