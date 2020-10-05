#include<bits\stdc++.h>

using namespace std;

int main()
{
    queue<int>q1;
    queue<int>q2;

    for(int i=100;i<105;i++)
        q1.push(i);

    for(int j=0;j<5;j++)
        q2.push(j);

    q1.swap(q2);
    return 0;
}
