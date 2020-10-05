#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,c,b,mid,l,r,i,tmp=0,tc=1000;

    cin>>n>>c;
    l=1;
    r=n;
    while(1)
    {
        mid=(l+r)/2;
        cout<<1<<" "<<mid<<"\n";
        cin>>b;
        if(b==1)
        {
          //  r=mid-1;
            tmp=mid;
            while(1)
            {
                mid=(l+r)/2;
                cout<<1<<" "<<mid<<"\n";
                cin>>b;
                r=mid-1;
                if(b==1)
                    tmp=mid;
                if(b==0)
                    break;

            }
            if(b==0)
                break;
        }
        if(b==0)
        {
            l=mid+1;
        }
    }
    cout<<3<<" "<<tmp;
    return 0;
}
