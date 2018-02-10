/*
    BIT  - Inversion count 
    Same as that of 
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

typedef long long ll;
typedef map<int, int> mii; 
typedef pair<int, int> pii;

ll tree[MAX];
int dat[MAX];
int n;

void update(int idx, int val)
{
    while(idx<=n)
    {
        //printf("%d ", idx);
        tree[idx]+=val;
        idx+=idx&-idx;
    }
}

ll read(int idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=idx&-idx;
    }
    return sum;
}

int main()
{
    scanf("%d", &n);
    int x, y, males[MAX], females[MAX];
    mii m, f;
    vector<pii> arr;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &x, &y);
        males[i]=x;
        females[i]=y;
        arr.push_back(pii(x, y));
    }
    sort(males, males+n);
    sort(females, females+n);
    for(int i=0;i<n;i++)
    {
        m[males[i]]=i+1;
        f[females[i]]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        x=m[arr[i].first];
        y=f[arr[i].second];
        //printf("%d %d\n", x, y);
        dat[x]=y;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=(read(n)-read(dat[i]));
        //printf("->%d\n", dat[i]);
        update(dat[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}

