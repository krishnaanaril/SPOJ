#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef unsigned long long ull;

ull bigpow(ull a, ull b)
{
    ull ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;
    ull a, s;
    cin>>t;
    while(t--)
    {
        s=1;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            s=(s*(a)%MOD)%MOD;
        }
        cout<<bigpow(s, 3)<<endl;
    }
    return 0;
}
