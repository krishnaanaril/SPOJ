#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 100005 

int main()
{
    ll t, n, k, val, ans;
    scanf("%lld", &t);
    while(t--)
    {
        ans=0;
        scanf("%lld%lld", &n, &k);
        for(int i=0;i<n;i++)
        {
            scanf("%lld", &val);
            ll tmp=val%k;
            
            ans+=(tmp>k/2)?k-tmp:tmp;
            //printf("1. %lld %lld %lld\n", tmp, k-tmp, ans);
        }
        printf("%lld\n", ans);
    }
}
