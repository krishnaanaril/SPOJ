/*
    Codechef: FOMBRO  - Feb-Cooxkoff-2015
    Date: 2/20/2015
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 1000001

int ans, t, n, m, q, r, fordp[MAX], betdp[MAX], backdp[MAX];

ll binpow(ll a, ll b, ll M)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        fordp[0]=backdp[0]=1;
        for(int i=1;i<=n/2;i++)
        {
            fordp[i]= (fordp[i-1]*binpow(i, i-1, m))%m;
        }
        for(int i=1;i<=n/2;i++)
        {
            backdp[i]=(backdp[i-1]*binpow(n-i+1, i, m))%m;
        }
        if(n&1)
            betdp[n/2]=n/2+1;
        else
            betdp[n/2]=1;
        for(int i=n/2-1;i>=1;i--)
        {
            betdp[i]=((ll)((betdp[i+1]*(i+1))%m)*(ll)(n-i))%m;
        }
        while(q--)
        {
            cin>>r;
            r=min(r, n-r);
            ans=((ll)((fordp[r]*binpow(betdp[r], r, m))%m * backdp[r])%m);
            cout<<ans<<endl;
        }
    }
    return 0;
}

