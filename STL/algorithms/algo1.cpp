#include<bits\stdc++.h>
using namespace std;

int main()
{
    int a[5]={15,8,9,6,5};
    int b[5]={15,8,9,6,5};
    int c[5]={15,8,9,6,6};
    int d[5]={15,8,9,6,5};
    vector<int>d1;

int x;


    sort(a ,a+5);
    reverse(b ,b+5);
    cout<<*max_element(c ,c+5);
        cout<<"\n";
    cout<<*min_element(c ,c+5);
    cout<<"\n";
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";

        cout<<"\n";
     for(int i=0;i<5;i++)
        cout<<b[i]<<" ";

    cout<<"\n"<<accumulate(c ,c+5,0)<<"\n";

     cout<<"\n"<<count(c ,c+5 ,6)<<"\n";

      if(find(c ,c+5,8))
            cout<<"\nfound\n";
      else
            cout<<"\nNot found";

      if(binary_search(c ,c+5,8))       //for binary serach athe array needs to be sorted
            cout<<"\nfound\n";
      else
            cout<<"\nNot found";

        if(binary_search(a ,a+5,8))
            cout<<"\nfound\n";
        else
            cout<<"\nNot found";

    cout<<"\n"<<*lower_bound(d ,d+5 ,6)<<"\n";
    cout<<"\n"<<*upper_bound(d ,d+5 ,6)<<"\n";

  //  d.erase(1);//erases the elemnt whose index is two
//    c.erase(unique(c ,c+5),c+5);//removes duplicate
     cout<<"\n";
     for(int i=0;i<5;i++)
        cout<<d[i]<<" ";

    cout<<"\n"<<next_permutation(d ,d+5)<<"\n";//ghg ggh  abc cab
    cout<<"\n"<<prev_permutation(d ,d+5)<<"\n";
//cout<<"\n"<<distance(d ,d+3)<<"\n";


    return 0;
}
