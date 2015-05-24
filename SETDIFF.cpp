#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll bigMod(ll a, ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, tmp, n;
    vector<int> dat;
    ll suma, sumb, ltmp, ans;
    cin>>t;
    while(t--)
    {
        dat.clear();
        suma=sumb=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            dat.push_back(tmp);
        }
        sort(dat.begin(), dat.end());
        for(int i=0;i<n;i++)
        {
            ltmp = (bigMod(2, n-1-i)*dat[i])%MOD;
            suma = (suma+ltmp)%MOD;
        }
        for(int i=0;i<n;i++)
        {
            ltmp = (bigMod(2, i)*dat[i])%MOD;
            sumb = (sumb+ltmp)%MOD;
        }
        ans= (sumb-suma+MOD)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
