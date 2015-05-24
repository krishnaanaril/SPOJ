#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main()
{
    int n, tmp, mid, succ=0, fail=0;
    vi dat, arr;
    ll x;
    scanf("%d%lld", &n, &x);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &tmp);
        dat.push_back(tmp);
        arr.push_back(0);
    }
    sort(dat.begin(), dat.end());
    for(int i=0;i<n;i++)
    {
        mid=ceil(dat[i]/2.0);
        if(x-mid>=0)
        {
            arr[i]=mid;
            x-=mid;
        }
        else
            break;
    }
    for(int i=0;i<n;i++)
    {
        mid=dat[i]-arr[i];
        if(mid<=x)
        {
            arr[i]=dat[i];
            x-=mid;
            succ++;
        }
        else if(arr[i]< ceil(dat[i]/2.0))
            fail++;
    }
    printf("%d %d\n", fail, succ);
    return 0;
}
