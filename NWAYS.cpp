#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if(!b)
        return a;
    return gcd(b, a%b);
}

void DivideByGcd(ll &a, ll &b)
{
    ll g=gcd(a, b);
    a/=g;
    b/=g;
}

inline ll getWays(ll n, ll k)
{
    //printf("4. %lld %lld\n", n, k);
    ll num=1, den=1, toMul, toDiv;
    if(k>n/2) k=n-k;
    for(int i=k;i;i--)
    {
        toMul=n-k+i;
        toDiv=i;
        DivideByGcd(toMul, toDiv);
        DivideByGcd(num, toDiv);
        DivideByGcd(toMul, den);
        num*=toMul;
        den*=toDiv;
    }
    return num/den; 
}

int main()
{
    ll t, n, k;
    ll ans=0;
    scanf("%lld", &t);
    while(t--)
    {
        ans=0;
        scanf("%lld%lld", &n, &k);
        ans+=n*getWays(k, k);
        //printf("1. %lld\n", ans);
        for(int i=1;i<n;i++)
        {
            ans+=(2*n-2*i)*getWays(k+i, i);
            //printf("2. %lld %lld\n", (2*n-2*i), getWays(k+i, i));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
