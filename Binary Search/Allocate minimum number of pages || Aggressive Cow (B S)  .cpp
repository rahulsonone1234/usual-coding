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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
bool allocate_book(int a[], int n, int curr_min, int k)
{
    int sum=0;
    int cnt=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>curr_min)
        return false;
        
        if(sum+a[i] > curr_min)
        {
            cnt++;
            sum=a[i];
            
            if(cnt>k)
            return false;
        }
        else
        {
            sum+=a[i];
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    int maxval=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        maxval=max(maxval, a[i]);
    }
    int k;
    cin>>k;
    
    if(n<k){cout<<"Not Possible"<<endl;}
    
    int l=maxval;
    int h=sum;
    int mid;
    int res=INT_MAX;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(allocate_book(a, n, mid, k))
        {
           res=min(res, mid);
           h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<res<<endl;
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;



const int me = 100025;
const int mod = 0x3b9aca07;


int t, n, c;
int a[me];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t --){
        cin >> n >> c;
        for(int i = 0; i < n; i ++)
            cin >> a[i];
        
        sort(a, a + n);
        int low = 0, high = a[n-1], mid, best = 0;
        while(low <= high){
            mid = (low + high + 1) / 2;
            int cnt = 1, left = 0;
            for(int i = 1; i < n && cnt < c; i ++){
                if(a[i] - a[left] >= mid)
                    left = i, cnt ++;
            }
            if(cnt >= c){
                best = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout << best << endl;
    }
    
    return 0;
}
