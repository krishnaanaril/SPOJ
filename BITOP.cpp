/*
    Useful BIT operations 
    Source: Topcoder - bmerry
    Date: 3/29/2015 
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a=0, b=3;
    
    /*
    //set union
    cout<<(a|b)<<endl;
    
    //set intersection
    a=1, b=3;
    cout<<(a&b)<<endl;
    
    //set subtraction
    a=3, b=1;
    cout<<(a & (~b))<<endl;
    
    //count the number of elements in a
    a=3;
    cout<<__builtin_popcount(a)<<endl;
    
    
    //Test set is non empty
    a=3;
    cout<<(a!=0)<<endl;
    
    
    //Index of the smallest element in a
    a=8;
    cout<<__builtin_ctz(a)<<endl;
    
    //Test whether element b is in a
    a=3, b=1;
    cout<<((a & (1<<b))!=0)<<endl;
    */
    
    //Remove the smallest element in a
    a=6;
    a = a & (a-1);
    cout<<a<<endl;
    
    //Remove all except small
    a=6;
    a = a & ~(a-1);
    cout<<a<<endl;
    return 0;
}
