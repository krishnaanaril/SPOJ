/*
    BIT  - Inversion count
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

typedef pair<int, int> pi;
typedef long long ll;

int n, m, k;
ll tree[MAX]; 
vector<pi> dat;


void update(int idx)
{
    while(idx<=m)
    {
        tree[idx]+=1;
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
    int t, x, y;
    ll ans;
    scanf("%d", &t);
    //while(t--)
    for(int j=1;j<=t;j++)
    {
        dat.clear();
        memset(tree, 0, sizeof(tree));
        scanf("%d%d%d", &n, &m, &k);
        for(int i=0;i<k;i++)
        {   
            scanf("%d%d", &x, &y);
            dat.push_back(pi(x, y));
        }
        sort(dat.begin(), dat.end());
        ans=0;
        for(int i=0;i<k;i++)
        {
            ans+=(read(m)-read(dat[i].second));
            update(dat[i].second);
        }
        printf("Test case %d: %lld\n", j, ans);
    }
    return 0;
}
