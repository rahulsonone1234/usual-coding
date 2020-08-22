Reverse Words In A Given String
Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr

// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     while(n--)
//     {
//       string s;
//       cin>>s;
//       reverse(s.begin() ,s.end());
//       string tmp="";
//       for(int i=0;i<s.length();i++)
//       {
//           if(s[i]!='.')
//           {
//               tmp+=s[i];
//           }
//           else
//           {
//               reverse(tmp.begin() ,tmp.end());
//               cout<<tmp<<".";
//               tmp="";
//           }
//       }
//       reverse(tmp.begin() ,tmp.end());
//       cout<<tmp<<endl;
      
//     }
//     return 0;
// }

/*#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        string tmp;
        stack<string>s1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                s1.push(tmp);
                tmp.clear();
                continue;
            }
            tmp+=s[i];
        }
        s1.push(tmp);
        while(!s1.empty())
        {
            string tmp;
            tmp=s1.top();
            cout<<tmp<<(s1.size()!=1?".":"");
            s1.pop();
        }
        
        cout<<endl;
    }
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    string s;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        getline(cin ,s);
        stringstream ss(s);
        stack<string>s1;
        string word;
        while(getline(ss, word,'.'))
        {
            s1.push(word);
        }
        while(!s1.empty())
        {
            cout<<s1.top()<<(s1.size()!=1?".":"");
            s1.pop();
        }
        cout<<endl;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////
Permutations of a given string
Given a string S. The task is to print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA

Explanation:
Testcase 1: Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .
 
using namespace std;

int main() {
	//code
	  int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        do
        {
            cout<<s<<" ";
        }while( next_permutation(s.begin(),s.end()));
        cout<<endl;
        
    }
	return 0;
}
//////////////////////////////////////////////////////////////////
Longest Palindrome in a String
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Input:
The first line of input consists number of the testcases. The following T lines consist of a string each.

Output:
In each separate line print the longest palindrome of the string given in the respective test case.

Constraints:
1 ≤ T ≤ 100
1 ≤ Str Length ≤ 104

Example:
Input:
1
aaaabbaa

Output:
aabbaa

Explanation:
Testcase 1: The longest palindrome string present in the given string is "aabbaa".


using namespace std;

void lps(string s)
{
    if(s.size()==0)
    {
        cout<<"String is Empty"<<endl;
    }
    const int n=s.size();
    // dp(i, j): indicates if string[i:j] is palindromic or not
    vector<vector<bool>>dp(n, vector<bool>(n, false));
    int max_len=0;
    int st=0;
    
    //for a single char they all are palindrome
    for(int i=0;i<n;i++)
    {
        dp[i][i]=true;
    }
    
    //for two and more char
    max_len=1;st=0;
    for(int l=1;l<n;l++)
    {
        for(int i=0;i<n-l;i++)
        {
            int j=i+l;
            // when there are only 2 chars, just check the first and last chars
            if(j-i+1==2)
            {
                dp[i][j]=s[i]==s[j];
            }
            else
            {
                // current s[i:j] can only be palindromic iff
                // first and last chars are same and the substring s[i+1:j-1]
                // is also palindromic
                dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1])==true;
            }
            // update max length
            if(dp[i][j]&&j-i+1>max_len)
            {
                max_len=j-i+1;
                st=i;
            }
        }
    }
    cout<<s.substr(st, max_len)<<endl;
    //string s1=s.substr(st, max_len);
    //cout<<s1.length()<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        lps(s);
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////

Implement strstr
Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. The function returns and integer denoting the first occurrence of the string x in s (0 based indexing).

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The first line of each test case contains two strings s and x.

Output:
For each test case, in a new line, output will be an integer denoting the first occurrence of the x in the string s. Return -1 if no match found.

Your Task:
Since this is a function problem, you don't have to take any input. Just complete the strstr() function which takes two strings str, target as an input parameter. The function returns -1 if no match if found else it returns an integer denoting the first occurrence of the x in the string s.

Expected Time Complexity: O(|s|*|x|)
Expected Auxiliary Space: O(1)

Note : Try to solve the question in constant space complexity.

Constraints:
1 <= T <= 200
1 <= |s|,|x| <= 1000

Example:
Input
2
GeeksForGeeks Fr
GeeksForGeeks For
Output
-1
5

Explanation:
Testcase 1: Fr is not present in the string GeeksForGeeks as substring.
Testcase 2: For is present as substring in GeeksForGeeks from index 5 (0 based indexing).
 #include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     //Your code here
     return s.find(x);
}
///////////////////////////////////////////////////////////////
Implement Atoi 
Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.
 
Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains a string str .
Output:
For each test case in a new line output will be an integer denoting the converted integer, if the input string is not a numerical string then output will be -1.

Your Task:
Complete the function atoi() which takes a string as input parameter and returns integer value of it. if the input string is not a numerical string then returns 1..

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=T<=100
1<=length of (s,x)<=10

Example(To be used only for expected output) :
Input:
2
123
21a

Output:
123
-1

Explanation:
Test Case 1: Integer value of '123' is 123.
Test Case 2: Output is -1 as all characters are not digit only.
using namespace std;

int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}// } Driver Code Ends


/*You are required to complete this method */
int atoi(string str)
{
    // stringstream ss(str);
    // int tmp;
    // char ch;
    // vector<int>v;
    // while(ss>>tmp)
    // {
    //     v.push_back(tmp);
    //     ss>>ch;
    // }
    // return v[0];
     for(int i=0;i<str.length();i++)
     {
        if(str[i]<='9' && str[i]>='0' || str[i]=='-')
           continue;
        else
           return -1;
     }
    int t=stoi(str);
    return t;
}

//////////////////////////////////////////////////////////////////////////////
Given two strings X and Y. The task is to find the length of the longest common substring.

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, first of which contains 2 space separated integers N and M denoting the size of string X and Y strings respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

Constraints:
1 <= T <= 200
1 <= N, M <= 100

Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1

Example:
Testcase 1: CDGH is the longest substring present in both of the strings.
 using namespace std;

int lcs(string s1, string s2,int n, int m)
{
    int dp[n+1][m+1]={0};
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                 ans=max(dp[i][j], ans);
            }
            else
            dp[i][j]=0;
        }
           
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        cout<<lcs(s1 ,s2 ,n ,m)<<endl;;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
Given a string s, recursively remove adjacent duplicate characters from the string s. The output string should not have any adjacent duplicates.
 

Input:
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. Each test case contains a string str.

Output:
For each test case, print a new line containing the resulting string.

Constraints:
1<=T<=100
1<=Length of string<=50

Example:
Input:
2
geeksforgeek
acaaabbbacdddd

Output:
gksforgk
acac


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string RmvDpl(string str)
{
    string res="";
    
    int i=0;
    while(i<str.size())
    {
        bool not_rpt=0;
        if(i<str.size()-1&&str[i]==str[i+1])
         {
             while(str[i]==str[i+1])
              i++;
             not_rpt=1;
         }
        
        if(not_rpt==0)
         res+=str[i];
        
        i++;
    }
    
    if(str.size()==res.size())
     return res;
    
    return RmvDpl(res);
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        string str;
        cin>>str;
        
        cout<<RmvDpl(str)<<endl;
        
    }

  
  return 0;
  
}
/////////////////////////////////////////////////////////////////////////////////
Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are anagram of each other or not. An anagram of a string is another string that contains same characters, only the order of characters can be different. For example, “act” and “tac” are anagram of each other.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consist of two strings in 'lowercase' only, in a single line.

Output:
Print "YES" without quotes if the two strings are anagram else print "NO".

Constraints:
1 ≤ T ≤ 300
1 ≤ |s| ≤ 106

Example:
Input:
2
geeksforgeeks forgeeksgeeks
allergy allergic

Output:
YES
NO

Explanation:
Testcase 1: Both the string have same characters with same frequency. So, both are anagrams.
Testcase 2: Characters in both the strings are not same, so they are not anagrams.
 
#include<bits/stdc++.h>
using namespace std;
string ana(string s1, string s2)
{
    int a[26]={0};
    int i;
    for(i=0;i<s1[i]&&s2[i];i++)
    {
        a[s1[i]]++;
        a[s2[i]]--;
    }
    if(s1[i]||s2[i])
    {
        return "NO";
    }
    for(i=0;i<=26;i++)
    {
        if(a[i])
        return "NO";
    }
    return"YES";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        cout<<ana(s1, s2)<<endl;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////

