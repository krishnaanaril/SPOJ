/*
    Classic implementation of insertion sort

*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int main()
{
    int dat[MAX];
    int n, j;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>dat[i];   
    for(int i=1;i<n;i++)
    {
        int temp=dat[i];
        for(j=i-1;j>=0;j--)
        {
            if(dat[j] > temp)
                dat[j+1]=dat[j];
            else
            {                
                break;
            }
        }
        dat[j+1]=temp;
    }
    cout<<"Sorted Numbers:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<dat[i]<<" ";
    }
    cout<<endl;
    return 0;
}
