/*
    SPOJ: HAYBALE
*/

#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

//int dat[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k, a, b, temp;
    vector<int> dat; 
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        dat.push_back(0);
    }
    for(int i=0;i<k;i++)
    {
        cin>>a>>b;
        dat[a-1]=1;
        dat[b]=-1;
    }
    for(int i=1;i<n;i++)
    {
        dat[i]+=dat[i-1];
    }
        for(int i=0;i<n;i++)
    {
        cout<<dat[i]<<" ";
    }
    cout<<endl;
    sort(dat.begin(), dat.end());
    for(int i=0;i<n;i++)
    {
        cout<<dat[i]<<" ";
    }
    cout<<endl;
    cout<<dat[n/2]<<endl;
    return 0;
}
