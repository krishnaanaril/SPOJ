/*
    
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int dat[MAX], temp[MAX];

int merge(int l, int m, int r )
{
    int i=l, j=m, k=0, inv=0;
    while(i<m && j<=r)
    {
        if(dat[i] < dat[j])
            temp[k++]=dat[i++];
        if(dat[i] > dat[j])
        {
            temp[k++]=dat[j++];
            inv=inv+(m-i);
        }
    }
    while(i<m)
    {
        temp[k++]=dat[i++];
    }
    while(j<=r)
    {
        temp[k++]=dat[j++];
    }
    return inv;
}

int mergesort(int l, int r)
{
    int inv=0;
    if(r>l)
    {
        int mid=l+(r-l)/2;
        //cout<<r<<" : "<<l<<" : "<<mid<<endl;
        inv+=mergesort(l, mid);
        inv+=mergesort(mid+1, r);
        inv+=merge(l, mid+1, r);
    }
    return inv;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>dat[i];
    }
    cout<<mergesort(0, n-1)<<endl;
    return 0;
}
