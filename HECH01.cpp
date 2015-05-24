#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int bigMod(int a, int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
        {
            res=(1LL*res*a)%MOD;
        }
        a=(1LL*a*a)%MOD;
        b>>=1;
    }
    return res;
}

int main()
{
    int t, x, a, b;
    vector<int> prime, power;
    cin>>t;
    while(t--)
    {
        cin>>x;
        for(int i=0;i<x;i++)
        {
            cin>>a;
            prime.push_back(a);
        }
        for(int i=0;i<x;i++)
        {
            cin>>b;
            power.push_back(b);
        }
        int lim=1, start=1;
        for(int i=0;i<x;i++)
        {
            start=(start*prime[i])%MOD;
            lim=(lim*bigMod(prime[i], power[i]))%MOD;
        }
        //cout<<start<<" : "<<lim<<endl;
        int ans=0, i=2;
        while(start<=lim)
        {
            ans=(ans+start)%MOD;
            start=(start*i)%MOD;
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
