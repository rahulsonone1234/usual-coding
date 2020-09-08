#include<stdio.h>
#include<stdlib.h>
#define M 5
typedef struct stack
{
	int top;
	int x[M];
}STK;

void init(STK *t)
{
	t->top=-1;
}

int isempty(STK *t)
{
	return (t->top==-1);
}
int isfull(STK *t)
{
	if(t->top==M-1)
	return 1;
	else
	return 0;
}
int stacktop(STK *t)
{
	return (t->x[t->top]);
}

void push(STK *t,int d)
{
	if(t->top==M-1)
	{
		printf("\nOverflow\n");
		return ;
	}
	t->top++;
	t->x[t->top]=d;
}

int pop(STK *t)
{
	if(t->top==-1)
	{
		printf("\nUnderflow\n");
		return 0;
	}
	else
	return (t->x[t->top--]);
}
void display(STK *t)
{
	int i=t->top;
	if(t->top==-1)
	{
		printf("\nStack is Empty\n");
		return ;
	}
	else
	{
		printf("\n Data: ");
		while(i>0)
		{
			printf("%4d ",t->x[i]);
			i--;
		}
	}
}
//Balanced the brackets
string isBalanced(string s) {
    stack<char>st;
    for(auto c:s)
    {
        switch(c)
        {
            case '{':
            case '(':
            case '[':
                    st.push(c);
                    break;
            case '}':
                    if(st.empty()||st.top()!='{')
                    {
                        return "NO";
                    }
                    st.pop();
                    break;
            case ')':
                    if(st.empty()||st.top()!='(')
                    {
                        return "NO";
                    }
                    st.pop();
                    break;
            case ']':
                    if(st.empty()||st.top()!='[')
                    {
                        return "NO";
                    }
                    st.pop();
                    break;
            
        }
    }
    return st.empty()?"YES":"NO";
}

//equal stack cylinder
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) 
{
    /*
     * Write your code here.
     */
     int sum1=0,sum2=0,sum3=0;
     for(int i=h1.size()-1;i>=0;i--)
     sum1+=h1[i];     

     for(int i=h2.size()-1;i>=0;i--)
     sum2+=h2[i];
     

     for(int i=h3.size()-1;i>=0;i--)
     sum3+=h3[i];
     

    int top1=0,top2=0,top3=0;
     while(1)
     {
        if(h1.empty()||h2.empty()||h3.empty())
        return 0;
         if (sum1 == sum2 && sum2 == sum3) 
         return sum1; 
     
      if (sum1 >= sum2 && sum1 >= sum3) 
         sum1 -= h1[top1++]; 
      else if (sum2 >= sum3 && sum2 >= sum3) 
         sum2 -= h2[top2++]; 
      else if (sum3 >= sum2 && sum3 >= sum1) 
         sum3 -= h3[top3++];

         

     }
}
/*max element 
int main()
{
	stack<long int>s,m;
	m.push(-1);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			int z;
			cin>>z;
			s.push(z);
			if(z>m.top())
			m.push(z);
		}
		else if(x==2)
		{
			int q=s.top();
			if(q==m.top())
			m.pop();
			s.pop();
		}
		else if(x==3)
		{
			cout<<m.top()<<endl;
		}
	}
}*/
//longest area histogram
long largestRectangle(vector<int> h) 
{
    long maxarea=0;
    long area=0;
    long l=0;
    long r=0;
    for(int i=0;i<h.size();i++)
    {
        for( l=i;h[l]>=h[i];l--)
        {
            if(l<0)
            break;
        }
        for( r=i;h[r]>=h[i];r++)
        {
            if(r>=h.size())
            break;
        }
        area=h[i]*(r-l-1);
        if(area>maxarea)
        maxarea=area;
    }
    return maxarea;
}
long largestRectangle(vector<int> h) 
{
    int n=h.size();
    stack<int>s;
    int max=0;
    int area=0;
    int i=0,t;
    while(i<n)
    {
        if(s.empty()||h[s.top()]<=h[i])
        s.push(i++);
        else
        {
            t=s.top();
            s.pop();

            area=h[t]*(s.empty()?i:i-s.top()-1);
            if(area>max)
            max=area;
        }
    }
    while(!s.empty())
    {
        t=s.top();
        s.pop();
        area=h[t]*(s.empty()?i:i-s.top()-1);
            if(area>max)
            max=area;

    }
    return max;

}
//Queue using two stack
#include<bits/stdc++.h>
using namespace std;

stack<int>s1;
stack<int>s2;
void enqueue(int x)
{
        s1.push(x);
}

int dequeue()
{
    
    if(s2.empty())
    {
        if(s1.empty())
        {
            return -1;
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    int res=s2.top();
    s2.pop();
    return res;
}
/*void enQueue(int x) 
    { 
        // Move all elements from s1 to s2 
        while (!s1.empty()) { 
            s2.push(s1.top()); 
            s1.pop(); 
        } 
  
        // Push item into s1 
        s1.push(x); 
  
        // Push everything back to s1 
        while (!s2.empty()) { 
            s1.push(s2.top()); 
            s2.pop(); 
        } 
    } 
  
    // Dequeue an item from the queue 
    int deQueue() 
    { 
        // if first stack is empty 
        if (s1.empty()) { 
            cout << "Q is Empty"; 
            exit(0); 
        } 
  
        // Return top of s1 
        int x = s1.top(); 
        s1.pop(); 
        return x; 
    } */

int main()
{
    cout<<"dequeued element"<<dequeue()<<endl;
    enqueue(1);
    enqueue(8);
    enqueue(7);
    enqueue(56);
    cout<<"dequeued element"<<dequeue()<<endl;
    cout<<"dequeued element"<<dequeue()<<endl;
    return 0;
}
//efficient using one stack
#include<bits/stdc++.h>
using namespace std;

stack<int>s1;
void enqueue(int x)
{
        s1.push(x);
}

int dequeue()
{
    if(s1.empty())
    {
        cout<<"\nQueue is empty ";
        return 0;
    }
    int x=s1.top();
    s1.pop();
    
    if(s1.empty())
    return x;
    
    int item=dequeue();
    s1.push(x);
    return item;
    
}

int main()
{
    cout<<"dequeued element"<<dequeue()<<endl;
    enqueue(1);
    enqueue(8);
    enqueue(7);
    enqueue(56);
    cout<<"dequeued element"<<dequeue()<<endl;
    cout<<"dequeued element"<<dequeue()<<endl;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////
int main()
{
	STK t;
	init(&t);

	push(&t ,1);
	push(&t ,2);
	push(&t ,3);
	display(&t);
	pop(&t);
	push(&t ,4);
	push(&t ,6);
	display(&t);
	printf("\n%d Stacktop\n",stacktop(&t));
}

//////////////////////////////
/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   if(s.empty())
   return -1;
   else
   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.empty())
   return -1;
   
   int t=s.top();
   s.pop();
   
   if(t<minEle)
   {
       int x=minEle;
       minEle=2*minEle-t;
       return x;
   }
   else
   return t;
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty())
   {
       minEle=x;
       s.push(x);
       return;
   }
   
   
   if(x<minEle)
   {
       s.push(2*x-minEle);
       minEle=x;
   }
   else
   s.push(x);
   
}
/////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int arr[n];
        
        for(long long int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        arr[n]=0;
        stack<int>st;
        long long int i=0;
        long long int area=0;
        long long int maxarea=-1;
        
        while(i<n+1)
        {
            if(st.empty()||arr[i]>=arr[st.top()])
            {
                st.push(i++);
            }
            else
            {
                int tmp=st.top();
                st.pop();
                area=arr[tmp]*(st.empty()?i:i-st.top()-1);
                if(maxarea<area)
                {
                    maxarea=area;
                }
            }
        }
        cout<<maxarea<<endl;
    }
}
//////////////////////////////////////////////////////////////
//nearest smallest in array
vector<int> Solution::prevSmaller(vector<int> &arr) {
    stack<int>s;
    vector<int>ans;
    
    for(int i=0;i<arr.size();i++)
    {
        while(!s.empty() && s.top()>=arr[i])
        {
            s.pop();
        }
        
        if(s.empty())
        ans.push_back(-1);
        else
        ans.push_back(s.top());
        
        s.push(arr[i]);
    }
    return ans;
}
///////////////////////////////////////////////////////
//balanced paranthesis
int Solution::solve(string s) {
    stack<char>st;
    for(auto c: s)
    {
        switch(c)
        {
            case '(':
                    st.push(c);
                    break;
            case ')':
                    if(st.empty()||st.top()!='(')
                    {
                        return 0;
                    }
                    st.pop();
                    break;
        }
    }
    return st.empty()?1:0;
}
///////////////////////////////////////////////////////////////
//reduandant braces
int Solution::braces(string s)
{
    stack<char> st;
    int n = s.length();
 
    for(int i=0;i<n;i++)
    {
        if(s[i]==')')
        {
            char top = st.top();
            st.pop();
            bool flag=true;
 
            while(top!='(')
            {
                if(top=='+' || top=='-' || top=='*' || top=='/')
                    flag = false;
                top = st.top();
                st.pop();
            }
            if(flag)
                return 1;
        }
        else
            st.push(s[i]);
    }
    return 0;
}
//simplify path
string simplifyPath(string path)
{
    vector<string>v;
    istringstream ss(path);
    string token, res;
    
    while(getline(ss, token, '/'))
    {
        if(token=="" || token==".")
		continue;
        if(token!="..") 
		v.emplace_back(token);
        else if(!v.empty())
		v.pop_back();
    }
    
    for(auto i:v) res+="/"+i;
    return v.empty()?"/":res;
}

//next greater element
// A Stack based C++ program to find next 
// greater element for all array elements. 
#include <bits/stdc++.h> 
using namespace std; 

/* prints element and NGE pair for all 
elements of arr[] of size n */
void printNGE(int arr[], int n) { 
stack < int > s; 

/* push the first element to stack */
s.push(arr[0]); 

// iterate for rest of the elements 
for (int i = 1; i < n; i++) { 

	if (s.empty()) { 
	s.push(arr[i]); 
	continue; 
	} 

	/* if stack is not empty, then 
	pop an element from stack. 
	If the popped element is smaller 
	than next, then 
	a) print the pair 
	b) keep popping while elements are 
	smaller and stack is not empty */
	while (s.empty() == false && s.top() < arr[i]) 
	{		 
		cout << s.top() << " --> " << arr[i] << endl; 
		s.pop(); 
	} 

	/* push next to stack so that we can find 
	next greater for it */
	s.push(arr[i]); 
} 

/* After iterating over the loop, the remaining 
elements in stack do not have the next greater 
element, so print -1 for them */
while (s.empty() == false) { 
	cout << s.top() << " --> " << -1 << endl; 
	s.pop(); 
} 
} 

/* Driver program to test above functions */
int main() { 
int arr[] = {11, 13, 21, 3}; 
int n = sizeof(arr) / sizeof(arr[0]); 
printNGE(arr, n); 
return 0; 
}
/////////////////////////////////////////////////////////////////////////////////
