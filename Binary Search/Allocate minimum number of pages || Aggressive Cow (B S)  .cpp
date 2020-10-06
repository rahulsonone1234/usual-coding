#include<bits/stdc++.h>
using namespace std;
bool allocateBooks(int a[], int n, int mid, int k)
{
    int sum = 0, cnt = 1;
    for(int i = 0; i < n; i ++)
    {
        sum += a[i];
        if(sum > mid)
        {
            cnt ++;
            sum = a[i];
        }
    }
    return (cnt <= k);
}
int main() {
    int n;
    cin >> n;
    int a[n], sum = 0, maxval = 0;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        sum += a[i];
        maxval = max(maxval, a[i]);
    }
    int k;
    cin >> k;

    // find the minimum of max pages in books
    // Observation : when m = 1, ans = sum; while when m = n, ans = maxval
    // Thus when m increases ans decreases
    int lo = maxval, hi = sum;
    int mid;
    while(lo<hi) 
    {
        mid = lo + (hi - lo) / 2;
        if(allocateBooks(a, n, mid, k))
        {
            hi = mid;
        } 
        else
        {
            lo = mid + 1;
        }
    }
    cout << hi << "\n";
    return 0;
}
