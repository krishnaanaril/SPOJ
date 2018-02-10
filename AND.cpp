/*
    Codechef: AND
    Date: 1/21/2015
    Sample case:
    1 - 001
    2 - 010
    3 - 011
    4 - 100
    5 - 101
    
    f(0)=3, f(1)=2, f(2)=2
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, temp;
    vector<int> dat;
    int f[33], mask=1;
    ll sum=0;
    cin>>n;
    memset(f, 0, 33*sizeof(int));
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        dat.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        temp=0;
        while(dat[i])
        {
            f[temp] += (dat[i]&mask);
            dat[i]>>=1;
            temp++;
        }
    }
    for(int i=0;i<30;i++)
    {
        //cout<<i<<" : "<<f[i]<<endl;
        sum+=((ll)f[i]*(((ll)f[i])-1)/2*pow(2, i));
    }
    cout<<sum<<endl;
    return 0;
}
