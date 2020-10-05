#include<bits/stdc++.h>

using namespace std;

class mul
{
    int vall;
    public:
            mul(){}//constructor for the class
            mul(int val):vall{val}{}  //parameterizsed consturctor
            int operator() (int val)  //overloading of () operator
            {
                return val*vall;
            }
}; //functor are for saving the state of the object initalize to avoid the use of static variable and global declaration

int main()
{
    mul a(12); //object named a is created and initalization is done  with constructor is done to 12
    cout<<a(2)<<"\n"; // now these objects are used as a function and here 12 is multiplied by
    cout<<a(3)<<"\n";// now these object is use as function and here it si multiplied by 3

    return 0;
}
